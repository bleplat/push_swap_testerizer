/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_skipva.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:56:24 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 19:05:55 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>

#include "libft.h"

#include "ft_printf_defines.h"
#include "ft_printf_helpers.h"

static void	skipva_float(int conversion, struct s_va_list_container *sva)
{
	if (conversion & (FT_PRINTF_LENMOD_LONGLONG))
		va_arg(sva->ap, long double);
	else
		va_arg(sva->ap, double);
}

void		ft_printf_skipva(int conversion, t_va_list_c *sva)
{
	if (conversion & (FT_PRINTF_LENMOD_ADDRESS))
		va_arg(sva->ap, void*);
	else if (ft_strchr(FT_PRINTF_FLOATS_CHARS, conversion & 0xFF))
		skipva_float(conversion, sva);
	else if (conversion & (FT_PRINTF_LENMOD_INTMAX))
		va_arg(sva->ap, intmax_t);
	else if (conversion & (FT_PRINTF_LENMOD_PTRDIFF))
		va_arg(sva->ap, ptrdiff_t);
	else if (conversion & (FT_PRINTF_LENMOD_SIZE))
		va_arg(sva->ap, size_t);
	else if (conversion & (FT_PRINTF_LENMOD_LONGLONG))
		va_arg(sva->ap, long long);
	else if (conversion & (FT_PRINTF_LENMOD_LONG))
		va_arg(sva->ap, long);
	else
		va_arg(sva->ap, int);
}
