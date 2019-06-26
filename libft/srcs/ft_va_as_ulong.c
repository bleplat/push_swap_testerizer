/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_as_ulong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:43:42 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/12 17:25:30 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

unsigned long			ft_va_as_ulong(va_list dont_touch)
{
	va_list				ap2;
	unsigned long		to_return;

	va_copy(ap2, dont_touch);
	to_return = va_arg(ap2, unsigned long);
	va_end(ap2);
	return (to_return);
}
