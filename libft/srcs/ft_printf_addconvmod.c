/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_addconvmod.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:19:11 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 19:06:55 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ft_printf_defines.h"
#include "ft_printf_helpers.h"

void				ft_printf_addconvmod_dinoux(unsigned int *conv, char **mod)
{
	if (ft_printf_popstr(mod, "hh"))
		*conv |= FT_PRINTF_LENMOD_CHAR;
	else if (ft_printf_popstr(mod, "ll"))
		*conv |= FT_PRINTF_LENMOD_LONGLONG;
	else if (ft_printf_popstr(mod, "h"))
		*conv |= FT_PRINTF_LENMOD_SHORT;
	else if (ft_printf_popstr(mod, "l"))
		*conv |= FT_PRINTF_LENMOD_LONG;
	else if (ft_printf_popstr(mod, "j"))
		*conv |= FT_PRINTF_LENMOD_INTMAX;
	else if (ft_printf_popstr(mod, "t"))
		*conv |= FT_PRINTF_LENMOD_PTRDIFF;
	else if (ft_printf_popstr(mod, "z"))
		*conv |= FT_PRINTF_LENMOD_SIZE;
}

void				ft_printf_addconvmod_aefg(unsigned int *conv, char **mod)
{
	if (ft_printf_popstr(mod, "ll"))
		*conv |= FT_PRINTF_LENMOD_LONGLONG;
	else if (ft_printf_popstr(mod, "l"))
		*conv |= 0;
	else if (ft_printf_popstr(mod, "L"))
		*conv |= FT_PRINTF_LENMOD_LONGLONG;
}

void				ft_printf_addconvmod_cs(unsigned int *conv, char **mod)
{
	if (ft_printf_popstr(mod, "l"))
	{
		*conv = (*conv & 0xFFFFFF00) | ft_toupper(*conv & 0xFF);
	}
}
