/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_as_longdouble.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:58:13 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/11 17:58:36 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

long double				ft_va_as_longdouble(va_list dont_touch)
{
	va_list		ap2;
	long double	to_return;

	va_copy(ap2, dont_touch);
	to_return = va_arg(ap2, long double);
	va_end(ap2);
	return (to_return);
}
