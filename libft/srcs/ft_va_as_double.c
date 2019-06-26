/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_as_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:57:39 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/11 17:58:06 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

double				ft_va_as_double(va_list dont_touch)
{
	va_list		ap2;
	double		to_return;

	va_copy(ap2, dont_touch);
	to_return = va_arg(ap2, double);
	va_end(ap2);
	return (to_return);
}
