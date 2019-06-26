/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nextrstpart.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:53:45 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/27 20:20:36 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ft_printf.h"
#include "ft_printf_helpers.h"

/*
** ft_printf_onerstpart():
**
** Parse a single rstpart from a string format.
** Set next_fmt to the character following the parsed arg.
** Output to 'part'.
*/

int			ft_printf_nextrstpart(
					char **next_fmt, char *fmt, t_printf_rstpart *part)
{
	if (*fmt == '%')
	{
		fmt++;
		return (ft_printf_nextrstpart_percent(next_fmt, fmt, part));
	}
	if (*fmt == '{')
	{
		fmt++;
		return (ft_printf_nextrstpart_bracket(next_fmt, fmt, part));
	}
	*next_fmt = ft_stranychr(fmt, "%{");
	part->str = ft_strsub(fmt, 0, (int)(*next_fmt - fmt));
	return (part->str == NULL);
}
