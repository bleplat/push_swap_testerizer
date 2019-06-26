/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_r.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:13:54 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 19:03:45 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ft_printf_defines.h"
#include "ft_printf_helpers.h"

static int	len_needs(t_printf_rstpart *part, char *s_ptr, int max_chars)
{
	int i_s;
	int ttl;

	i_s = 0;
	ttl = 0;
	while (s_ptr[i_s] != '\0')
	{
		if (part->fmt->options & FT_PRINTF_OPTION_ALT || ft_isprint(s_ptr[i_s]))
			ttl += 1;
		else
			ttl += 4;
		i_s++;
	}
	if (max_chars < 0)
		return (ttl);
	else
		return (ft_min(max_chars, ttl));
}

void		fill_str(t_printf_rstpart *part, char *s_ptr, int max_chars)
{
	int		i_s;
	int		i_d;

	i_s = 0;
	i_d = 0;
	while (s_ptr[i_s] != '\0' && (i_d < max_chars || max_chars == -1))
	{
		if (ft_isprint(s_ptr[i_s]))
			part->str[i_d] = s_ptr[i_s];
		else if (part->fmt->options & FT_PRINTF_OPTION_ALT)
			part->str[i_d] = '.';
		else
		{
			if (max_chars != -1 && (i_d + 3 >= max_chars))
				return ;
			part->str[i_d + 0] = '\\';
			part->str[i_d + 1] = 'x';
			part->str[i_d + 2] = "0123456789abcdef"[(s_ptr[i_s] >> 4) & 0x0F];
			part->str[i_d + 3] = "0123456789abcdef"[(s_ptr[i_s] >> 0) & 0x0F];
			i_d += 3;
		}
		i_d += 1;
		i_s++;
	}
}

/*
** See ft_printf_format()
*/

int			ft_printf_format_r(t_printf_rstpart *part, va_list ap)
{
	void	*s_ptr;
	int		max_chars;

	s_ptr = ft_va_as_ptr(ap);
	if (s_ptr == NULL)
	{
		part->str = ft_strdup("(null)");
		return ((part->str) ? 0 : -1);
	}
	max_chars = 0;
	if (part->fmt->precision_iap == FT_PRINTF_IAP_UNUSED)
		max_chars = -1;
	else
		max_chars = ft_max(-1, part->fmt->precision);
	part->str = ft_strnew(len_needs(part, s_ptr, max_chars));
	if (!part->str)
		return (-1);
	fill_str(part, s_ptr, max_chars);
	return ((part->str) ? 0 : -1);
}
