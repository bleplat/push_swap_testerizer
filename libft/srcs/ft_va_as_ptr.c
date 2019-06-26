/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_as_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:42:12 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/11 17:42:14 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

void				*ft_va_as_ptr(va_list dont_touch)
{
	va_list		ap2;
	void		*to_return;

	va_copy(ap2, dont_touch);
	to_return = va_arg(ap2, void*);
	va_end(ap2);
	return (to_return);
}
