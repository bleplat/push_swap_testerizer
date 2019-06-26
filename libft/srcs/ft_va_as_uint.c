/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_as_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:43:03 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/12 17:16:33 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

/*
** Read an int from a va_list.
** The given va_list will not be modified.
*/

unsigned int			ft_va_as_uint(va_list dont_touch)
{
	va_list			ap2;
	unsigned int	to_return;

	va_copy(ap2, dont_touch);
	to_return = va_arg(ap2, unsigned int);
	va_end(ap2);
	return (to_return);
}
