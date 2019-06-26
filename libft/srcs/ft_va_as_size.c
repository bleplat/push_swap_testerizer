/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_as_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:46:52 by bleplat           #+#    #+#             */
/*   Updated: 2019/01/24 18:09:19 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>

size_t				ft_va_as_size(va_list dont_touch)
{
	va_list		ap2;
	size_t		to_return;

	va_copy(ap2, dont_touch);
	to_return = va_arg(ap2, size_t);
	va_end(ap2);
	return (to_return);
}
