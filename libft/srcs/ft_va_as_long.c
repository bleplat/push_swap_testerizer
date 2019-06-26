/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_as_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:43:42 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/11 17:44:10 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

long				ft_va_as_long(va_list dont_touch)
{
	va_list		ap2;
	long		to_return;

	va_copy(ap2, dont_touch);
	to_return = va_arg(ap2, long);
	va_end(ap2);
	return (to_return);
}
