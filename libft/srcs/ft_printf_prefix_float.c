/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prefix_float.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:11:23 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 19:10:18 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "ft_printf_defines.h"
#include "ft_printf_helpers.h"

static int			get_zero_count(char sign, t_printf_rstpart *p, char *beg)
{
	int				zero_count;

	if (!(p->fmt->options & FT_PRINTF_OPTION_ZERO_PADDING))
		return (0);
	if (p->fmt->options & FT_PRINTF_OPTION_LEFT_ALIGN)
		return (0);
	zero_count = p->fmt->fieldw - ft_strlen(beg) - (sign != '\0');
	if (p->fmt->options & FT_PRINTF_OPTION_ALT && !ft_strchr(p->str, '.'))
		zero_count -= 1;
	return (ft_max(0, zero_count));
}

int					ft_printf_prefix_float(t_printf_rstpart *p)
{
	char		*new_str;
	char		sign;
	int			zero_count;
	char		*strbegin;

	sign = ft_printf_get_sign_char(p);
	strbegin = (p->str[0] == '-') ? p->str + 1 : p->str;
	zero_count = get_zero_count(sign, p, strbegin);
	new_str = ft_strnew((sign != 0) + zero_count + ft_strlen(p->str) + 1);
	if (!new_str)
		return (-1);
	if (sign != '\0')
		*ft_strchr(new_str, '\0') = sign;
	ft_memset(ft_strchr(new_str, '\0'), '0', zero_count);
	ft_strcat(new_str, strbegin);
	if (p->fmt->options & FT_PRINTF_OPTION_ALT && !ft_strchr(p->str, '.'))
		ft_strcat(new_str, ".");
	free(p->str);
	p->str = new_str;
	return (0);
}
