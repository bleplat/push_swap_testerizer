/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_readva.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:06:25 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 19:06:16 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ft_printf_defines.h"
#include "ft_printf_helpers.h"

unsigned long long	ft_printf_readva_uint(unsigned int conversion, va_list ap)
{
	if (conversion & (FT_PRINTF_LENMOD_ADDRESS))
		return ((unsigned long long)ft_va_as_ptr(ap));
	else if (conversion & (FT_PRINTF_LENMOD_INTMAX))
		return (ft_va_as_intmax(ap));
	else if (conversion & (FT_PRINTF_LENMOD_PTRDIFF))
		return (ft_va_as_ptrdiff(ap));
	else if (conversion & (FT_PRINTF_LENMOD_SIZE))
		return (ft_va_as_size(ap));
	else if (conversion & (FT_PRINTF_LENMOD_LONGLONG))
		return (ft_va_as_ulonglong(ap));
	else if (conversion & (FT_PRINTF_LENMOD_LONG))
		return (ft_va_as_ulong(ap));
	else if (conversion & (FT_PRINTF_LENMOD_SHORT))
		return (ft_va_as_ushort(ap));
	else if (conversion & (FT_PRINTF_LENMOD_CHAR))
		return (ft_va_as_uchar(ap));
	else
		return (ft_va_as_uint(ap));
}

signed long long	ft_printf_readva_sint(unsigned int conversion, va_list ap)
{
	if (conversion & (FT_PRINTF_LENMOD_ADDRESS))
		return ((signed long long)ft_va_as_ptr(ap));
	else if (conversion & (FT_PRINTF_LENMOD_INTMAX))
		return (ft_va_as_intmax(ap));
	else if (conversion & (FT_PRINTF_LENMOD_PTRDIFF))
		return (ft_va_as_ptrdiff(ap));
	else if (conversion & (FT_PRINTF_LENMOD_SIZE))
		return (ft_va_as_size(ap));
	else if (conversion & (FT_PRINTF_LENMOD_LONGLONG))
		return (ft_va_as_longlong(ap));
	else if (conversion & (FT_PRINTF_LENMOD_LONG))
		return (ft_va_as_long(ap));
	else if (conversion & (FT_PRINTF_LENMOD_SHORT))
		return (ft_va_as_short(ap));
	else if (conversion & (FT_PRINTF_LENMOD_CHAR))
		return (ft_va_as_char(ap));
	else
		return (ft_va_as_int(ap));
}

long double			ft_printf_readva_float(unsigned int conversion, va_list ap)
{
	if (conversion & (FT_PRINTF_LENMOD_LONG))
		return (ft_va_as_double(ap));
	else if (conversion & (FT_PRINTF_LENMOD_LONGLONG))
		return (ft_va_as_longdouble(ap));
	else
		return (ft_va_as_double(ap));
}
