/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_as_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:43:03 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/03 21:23:58 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>

/*
** Read a wchar_t from a va_list.
** The given va_list will not be modified.
*/

wchar_t				ft_va_as_wchar(va_list dont_touch)
{
	va_list		ap2;
	wchar_t		to_return;

	va_copy(ap2, dont_touch);
	to_return = va_arg(ap2, wchar_t);
	va_end(ap2);
	return (to_return);
}
