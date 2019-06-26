/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_as_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:39:31 by bleplat           #+#    #+#             */
/*   Updated: 2019/01/24 18:04:05 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

char				ft_va_as_char(va_list dont_touch)
{
	va_list		ap2;
	char		to_return;

	va_copy(ap2, dont_touch);
	to_return = va_arg(ap2, int);
	va_end(ap2);
	return (to_return);
}
