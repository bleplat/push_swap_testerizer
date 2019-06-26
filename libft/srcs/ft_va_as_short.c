/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_as_short.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:40:44 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/12 17:10:53 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

short				ft_va_as_short(va_list dont_touch)
{
	va_list				ap2;
	short				to_return;

	va_copy(ap2, dont_touch);
	to_return = va_arg(ap2, int);
	va_end(ap2);
	return (to_return);
}
