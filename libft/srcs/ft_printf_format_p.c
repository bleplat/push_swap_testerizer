/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:14:44 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 19:02:48 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ft_printf_defines.h"
#include "ft_printf_helpers.h"

/*
** See ft_printf_format()
*/

int			ft_printf_format_p(t_printf_rstpart *part, va_list ap)
{
	if (sizeof(void*) == sizeof(long))
		part->fmt->conversion = 'p' | FT_PRINTF_LENMOD_LONG;
	else
		part->fmt->conversion = 'p';
	part->fmt->options |= FT_PRINTF_OPTION_ALT;
	return (ft_printf_format_uints(part, ap));
}
