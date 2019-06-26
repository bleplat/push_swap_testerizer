/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_as_ptrdiff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:46:04 by bleplat           #+#    #+#             */
/*   Updated: 2019/01/24 18:08:58 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>

ptrdiff_t				ft_va_as_ptrdiff(va_list dont_touch)
{
	va_list		ap2;
	ptrdiff_t	to_return;

	va_copy(ap2, dont_touch);
	to_return = va_arg(ap2, ptrdiff_t);
	va_end(ap2);
	return (to_return);
}
