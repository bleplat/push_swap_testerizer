/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:27:16 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/27 22:14:17 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

/*
** ft_printf()
**
** Format and print a string.
*/

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	int				to_return;

	va_start(ap, format);
	to_return = ft_vprintf(format, ap);
	va_end(ap);
	return (to_return);
}

/*
** ft_dprintf()
**
** Format and print a string to a file descriptor.
*/

int				ft_dprintf(int fd, const char *format, ...)
{
	va_list			ap;
	int				to_return;

	va_start(ap, format);
	to_return = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (to_return);
}

/*
** ft_asprintf()
**
** Allocate *ret with enough memoryto hold a formated string,
** and format it.
*/

int				ft_asprintf(char **dst, const char *format, ...)
{
	va_list			ap;
	int				to_return;

	va_start(ap, format);
	to_return = ft_vasprintf(dst, format, ap);
	va_end(ap);
	return (to_return);
}
