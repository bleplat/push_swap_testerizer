/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:04:03 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/27 20:04:50 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ft_printf.h"
#include "ft_printf_helpers.h"

/*
** ft_vprintf()
**
** Print a formated string to stdout.
** Same as ft_printf() but take a va_list instead of arbitrary arguments.
*/

int				ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}

/*
** ft_vdprintf()
**
** Print a formated string to a file descriptor.
** Same as ft_dprintf() but take a va_list instead of arbitrary arguments.
*/

int				ft_vdprintf(int fd, const char *format, va_list ap)
{
	int			to_return;
	char		*to_print;

	to_print = NULL;
	to_return = ft_vasprintf(&to_print, format, ap);
	if (to_print != NULL)
	{
		if (write(fd, to_print, to_return) < 0)
			to_return = -1;
		free(to_print);
	}
	return (to_return);
}

/*
** ft_vasprintf()
**
** Allocate *ret to hold a formated string,
** then put the formated string into it.
** Same as ft_format() but take a va_list instead of arbitrary arguments.
*/

int				ft_vasprintf(char **ret, const char *format, va_list ap)
{
	return (ft_printf_wrapped_entry(ret, format, ap));
}
