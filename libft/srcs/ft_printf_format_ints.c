/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_ints.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:03:20 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 19:00:01 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ft_printf_defines.h"
#include "ft_printf_helpers.h"

/*
** See ft_printf_format()
** Handle a signed decimal integer conversion.
*/

int			ft_printf_format_sints(t_printf_rstpart *part, va_list ap)
{
	signed long long		num;

	num = ft_printf_readva_sint(part->fmt->conversion, ap);
	if (num == 0
		&& part->fmt->precision_iap != FT_PRINTF_IAP_UNUSED
		&& part->fmt->precision == 0)
		part->str = ft_strdup("");
	else
		part->str = ft_lltoa(num);
	return (part->str ? 0 : -1);
}

/*
** See ft_printf_format()
** Handle an unsigned integer conversion.
*/

int			ft_printf_format_uints(t_printf_rstpart *part, va_list ap)
{
	unsigned long long		num;

	num = ft_printf_readva_uint(part->fmt->conversion, ap);
	if (num == 0
		&& part->fmt->precision_iap != FT_PRINTF_IAP_UNUSED
		&& part->fmt->precision == 0)
		part->str = ft_strdup("");
	else if ((part->fmt->conversion & 0xFF) == 'b')
		part->str = ft_ulltoa_basestr(num, "01");
	else if ((part->fmt->conversion & 0xFF) == 'o')
		part->str = ft_ulltoa_basestr(num, "01234567");
	else if ((part->fmt->conversion & 0xFF) == 'u')
		part->str = ft_ulltoa_basestr(num, "0123456789");
	else if ((part->fmt->conversion & 0xFF) == 'p')
		part->str = ft_ulltoa_basestr(num, "0123456789abcdef");
	else if ((part->fmt->conversion & 0xFF) == 'x')
		part->str = ft_ulltoa_basestr(num, "0123456789abcdef");
	if (!part->str)
		return (-1);
	return (0);
}

/*
** See ft_printf_format()
** Handle any integer conversion.
*/

int			ft_printf_format_integer(t_printf_rstpart *part, va_list ap)
{
	int		rst;

	if (ft_strchr("di", (part->fmt->conversion & 0xFF)))
		rst = ft_printf_format_sints(part, ap);
	else if ((part->fmt->conversion & 0xFF) == 'p')
		rst = ft_printf_format_p(part, ap);
	else
		rst = ft_printf_format_uints(part, ap);
	if (rst < 0)
		return (-1);
	if (ft_printf_prefix_int(part) < 0)
		return (-1);
	if (part->fmt->options & FT_PRINTF_OPTION_UPPER)
		ft_strtoupper_inplace(part->str);
	return (0);
}
