/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formatall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:15:15 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 18:57:25 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ft_printf_defines.h"
#include "ft_printf_helpers.h"

/*
** Set auto va_list indices (special index 0) to a true va_list index.
** apcs: ap (va_list) containers
*/

static void	resolve_asterixes(t_array *parts_a, t_va_list_c *apcs)
{
	int					i_part;
	t_printf_rstpart	*parts;

	parts = parts_a->items;
	i_part = 0;
	while (i_part < parts_a->item_count)
	{
		if (parts[i_part].fmt != NULL)
		{
			if (parts[i_part].fmt->fieldw_iap > 0)
				parts[i_part].fmt->fieldw = ft_va_as_int(
						apcs[parts[i_part].fmt->fieldw_iap].ap);
			if (parts[i_part].fmt->precision_iap > 0)
				parts[i_part].fmt->precision = ft_va_as_int(
						apcs[parts[i_part].fmt->precision_iap].ap);
			if (parts[i_part].fmt->precision < 0)
				parts[i_part].fmt->precision_iap = FT_PRINTF_IAP_UNUSED;
			if (parts[i_part].fmt->precision_iap == FT_PRINTF_IAP_UNUSED)
				parts[i_part].fmt->precision = -1;
		}
		i_part++;
	}
}

/*
** Final solving of rstparts. This is where several different function may
** be called. Sub-calls may also contains different possible calls.
*/

static int	format_each(t_array *parts_a, t_va_list_c *apcs)
{
	int					just;
	int					chars_printed;
	int					i_part;
	t_printf_rstpart	*parts;

	parts = parts_a->items;
	chars_printed = 0;
	i_part = 0;
	while (i_part < parts_a->item_count)
	{
		if (parts[i_part].str != NULL)
			chars_printed += ft_strlen(parts[i_part].str);
		else if (parts[i_part].fmt != NULL)
		{
			just = ft_printf_format(&parts[i_part],
				apcs[parts[i_part].fmt->iap].ap, chars_printed);
			if (just < 0)
				return (-1);
			chars_printed += just;
		}
		else
			return (-1);
		i_part++;
	}
	return (chars_printed);
}

/*
** ft_printf_formatall()
**
** Interpret a t_array of printf parts, reading ap.
** The goal is to get rid of variadic indexes, 1 by one, looping
** over all the parts, for 'star' special chars first, then to fix
** the whole array, to get strings instead of formats.
*/

int			ft_printf_formatall(t_array *parts_a, va_list ap)
{
	t_va_list_c		*apcs;
	int				ap_max;
	int				rst;

	ap_max = ft_printf_apvect(&apcs, parts_a, ap);
	if (!apcs)
		return (-1);
	resolve_asterixes(parts_a, apcs);
	rst = format_each(parts_a, apcs);
	ft_printf_endapvect(&apcs, ap_max);
	return (rst);
}
