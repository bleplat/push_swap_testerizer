/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_as_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:43:03 by bleplat           #+#    #+#             */
/*   Updated: 2019/01/17 19:26:19 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

/*
** Read an int from a va_list.
** The given va_list will not be modified.
*/

int					ft_va_as_int(va_list dont_touch)
{
	va_list		ap2;
	int			to_return;

	va_copy(ap2, dont_touch);
	to_return = va_arg(ap2, int);
	va_end(ap2);
	return (to_return);
}
