/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prefix_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:29:46 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 19:09:47 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "ft_printf_defines.h"
#include "ft_printf_types.h"

/*
** Return the sign prefix char used by a signed conversion.
*/

char				ft_printf_get_sign_char(t_printf_rstpart *p)
{
	if (ft_strchr(FT_PRINTF_SIGNEDS_CHARS, p->fmt->conversion & 0xFF))
	{
		if (p->str[0] == '-')
			return ('-');
		else if (p->fmt->options & FT_PRINTF_OPTION_SIGN)
			return ('+');
		else if (p->fmt->options & FT_PRINTF_OPTION_SPACE)
			return (' ');
	}
	return ('\0');
}

/*
** Return the prefix string this rstpart str should have.
** May also contains the negative sign.
*/

static const char	*get_prefix(t_printf_rstpart *p)
{
	if (!(p->fmt->options & FT_PRINTF_OPTION_ALT))
		return ("");
	if ((p->fmt->conversion & 0xFF) == 'p')
		return ("0x");
	if ((p->fmt->conversion & 0xFF) == 'o' && p->str[0] != '0')
		return ("0");
	if ((p->str[0] == '0' && p->str[1] == '\0') || p->str[0] == '\0')
		return ("");
	if ((p->fmt->conversion & 0xFF) == 'b')
		return ("0b");
	if ((p->fmt->conversion & 0xFF) == 'x')
		return ("0x");
	return ("");
}

/*
** Return the amount of zeros to add to the int str.
*/

static int			get_zero_count(const char *pref,
									char sign, t_printf_rstpart *p,
									char *beg)
{
	if (p->fmt->precision_iap != FT_PRINTF_IAP_UNUSED)
		return (ft_max(0, p->fmt->precision - (ft_strcmp("0", pref) == 0)
					- ft_strlen(beg)));
	else if (!(p->fmt->options & FT_PRINTF_OPTION_ZERO_PADDING))
		return (0);
	else if (p->fmt->options & FT_PRINTF_OPTION_LEFT_ALIGN)
		return (0);
	else if (p->fmt->precision_iap == FT_PRINTF_IAP_UNUSED)
		return (ft_max(0, p->fmt->fieldw
					- ft_strlen(pref) - (sign != '\0') - ft_strlen(beg)));
	else
		return (0);
}

/*
** May add prefixes to a string, depending of the integer conversion type.
*/

int					ft_printf_prefix_int(t_printf_rstpart *p)
{
	char		*new_str;
	const char	*prefix;
	char		sign;
	int			zero_count;
	char		*strbegin;

	prefix = get_prefix(p);
	sign = ft_printf_get_sign_char(p);
	strbegin = (p->str[0] != '-') ? p->str : p->str + 1;
	zero_count = get_zero_count(prefix, sign, p, strbegin);
	if (!(new_str = ft_strnew(ft_strlen(prefix) + (sign != '\0')
					+ zero_count + ft_strlen(strbegin))))
		return (-1);
	ft_strcat(new_str, prefix);
	if (sign != '\0')
		*ft_strchr(new_str, '\0') = sign;
	ft_memset(ft_strchr(new_str, '\0'), '0', zero_count);
	ft_strcat(new_str, strbegin);
	free(p->str);
	p->str = new_str;
	return (0);
}
