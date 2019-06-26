/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_floats.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:07:46 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 19:00:44 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ft_printf_defines.h"
#include "ft_printf_helpers.h"

/*
** See ft_printf_format()
** Handle floats conversions.
*/

int			ft_printf_format_float(t_printf_rstpart *part, va_list ap)
{
	long double		value;

	if (part->fmt->precision_iap == FT_PRINTF_IAP_UNUSED)
		part->fmt->precision = 6;
	value = ft_printf_readva_float(part->fmt->conversion, ap);
	part->str = ft_ldtoa(value, part->fmt->precision);
	if (ft_printf_prefix_float(part) < 0)
		return (-1);
	if (part->fmt->options & FT_PRINTF_OPTION_UPPER)
		ft_strtoupper_inplace(part->str);
	return (part->str ? 0 : -1);
}
