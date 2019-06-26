/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_others.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:16:22 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/28 16:20:55 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** See ft_printf_format()
*/

int			ft_printf_format_other(t_printf_rstpart *part, va_list ap)
{
	if ((part->fmt->conversion & 0xFF) == 's')
		return (ft_printf_format_s(part, ap));
	else if ((part->fmt->conversion & 0xFF) == 'c')
		return (ft_printf_format_c(part, ap));
	else if ((part->fmt->conversion & 0xFF) == 'y')
		return (ft_printf_format_y(part, ap));
	else if ((part->fmt->conversion & 0xFF) == 'r')
		return (ft_printf_format_r(part, ap));
	else
		return (ft_printf_format_unknow(part, ap));
	return (0);
}
