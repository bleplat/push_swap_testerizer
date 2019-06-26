/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_as_intmax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:45:11 by bleplat           #+#    #+#             */
/*   Updated: 2019/01/24 18:08:31 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdarg.h>

intmax_t				ft_va_as_intmax(va_list dont_touch)
{
	va_list		ap2;
	intmax_t	to_return;

	va_copy(ap2, dont_touch);
	to_return = va_arg(ap2, intmax_t);
	va_end(ap2);
	return (to_return);
}
