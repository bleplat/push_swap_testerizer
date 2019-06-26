/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_addoptionflag.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:36:02 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 19:07:18 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_defines.h"

/*
** Read option flags.
** Return 0 when there is no more flags.
*/

int				ft_printf_addoptionflag(int *options, char **fmt)
{
	if (**fmt == '#')
		*options |= FT_PRINTF_OPTION_ALT;
	else if (**fmt == '0')
		*options |= FT_PRINTF_OPTION_ZERO_PADDING;
	else if (**fmt == '-')
		*options |= FT_PRINTF_OPTION_LEFT_ALIGN;
	else if (**fmt == ' ')
		*options |= FT_PRINTF_OPTION_SPACE;
	else if (**fmt == '+')
		*options |= FT_PRINTF_OPTION_SIGN;
	else if (**fmt == '\'')
		*options |= FT_PRINTF_OPTION_THOUSANDS;
	else if (**fmt == '=')
		*options |= FT_PRINTF_OPTION_MIDDLE;
	else
		return (0);
	(*fmt) += 1;
	return (1);
}
