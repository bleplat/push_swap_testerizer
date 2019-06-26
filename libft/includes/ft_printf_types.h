/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:14:06 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 18:50:28 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPES_H
# define FT_PRINTF_TYPES_H

# include <stdarg.h>

/*
** t_printf_format
**
** Used to store formating values, and informations requiered to compose the
** the string, got from parsing a percent in a format string.
** Negative lenght and precision means it's an index (use absolute value).
*/

typedef struct							s_printf_format
{
	int					iap;
	int					options;
	int					fieldw_iap;
	int					fieldw;
	int					precision_iap;
	int					precision;
	unsigned int		conversion;
}										t_printf_format;

/*
** t_printf_rstpart
**
** Represent a component of a format string.
** If 'str' is not NULL, store a string to be concatened with other
** to make the finl result.
** Else, store in 'fmt' informations about how to retrieve 'str', or
** what action to do (cf %n).
*/

typedef struct							s_printf_rstpart
{
	char				*str;
	t_printf_format		*fmt;
	int					at_null;
}										t_printf_rstpart;

/*
** t_va_list_container
** t_va_list_c
**
** Contains a va_list.
** The purpose of it is to be able to store a va_list and give a pointer
** to it, because depending of the plateform, passing a va_list as pointer
** may not be possible.
*/

typedef struct							s_va_list_container
{
	va_list		ap;
}										t_va_list_container;
typedef t_va_list_container				t_va_list_c;

#endif
