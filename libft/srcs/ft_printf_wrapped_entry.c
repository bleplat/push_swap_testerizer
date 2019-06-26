/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wrapped_entry.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:14:45 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/27 20:07:11 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** ft_printf_wrapped_entry()
**
** Entry of the abstract part of the ft_printf.
** This function may be called by a few wrappers.
** Do exactly the same as ft_vasprintf() do.
*/

int			ft_printf_wrapped_entry(char **ret, const char *fmt, va_list ap)
{
	char		*generated;
	t_array		*parts_a;
	int			chars_printed;

	parts_a = ft_printf_rstparts_get(fmt);
	if (!parts_a)
		return (-1);
	if ((chars_printed = ft_printf_formatall(parts_a, ap)) < 0)
	{
		ft_printf_rstparts_clean(&parts_a);
		return (-1);
	}
	generated = ft_printf_rstparts_fuse(parts_a);
	ft_printf_rstparts_clean(&parts_a);
	if (!generated)
		return (-1);
	*ret = generated;
	return (chars_printed);
}
