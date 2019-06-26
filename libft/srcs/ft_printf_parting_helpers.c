/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parting_helpers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:03:14 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 18:56:19 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ft_printf_defines.h"
#include "ft_printf_helpers.h"

/*
** Move *format after str if format begins with it, and return 1.
*/

int			ft_printf_popstr(char **format, const char *str)
{
	if (ft_strbegins(*format, str))
	{
		(*format) += ft_strlen(str);
		return (1);
	}
	return (0);
}

/*
** Move *format after c if format begins with it, and return 1.
*/

int			ft_printf_popchar(char **format, char c)
{
	if (**format == c)
	{
		(*format) += 1;
		return (1);
	}
	return (0);
}

/*
** Try to read an unsigned int not begining with '0'.
** On success move *format after the int and return 1.
*/

int			ft_printf_popint(int *cr_int, char **format)
{
	if (ft_isdigit(**format) && **format != '0')
	{
		*cr_int = ft_atoi(*format);
		*format += ft_intsize(*cr_int);
		return (1);
	}
	return (0);
}

/*
** Read a field that could be retrievered from variadic agrgs,
** having a va_list index or being automatic.
** cr_int: current integer / last integer that have been read
** v: value to set
** v_iap: va_list index of the value to set
*/

int			ft_printf_w_or_p(int *cr_int, int *v, int *v_iap, char **fmt)
{
	*v_iap = FT_PRINTF_IAP_UNUSED;
	ft_printf_popint(cr_int, fmt);
	if (*cr_int == 0 && ft_printf_popchar(fmt, '*'))
	{
		ft_printf_popint(cr_int, fmt);
		if (*cr_int != 0 && ft_printf_popchar(fmt, '$'))
			*v_iap = *cr_int;
		else
			*v_iap = 0;
		*cr_int = 0;
	}
	else
	{
		*v = *cr_int;
		*v_iap = FT_PRINTF_IAP_UNDEFINED;
		*cr_int = 0;
	}
	return (0);
}
