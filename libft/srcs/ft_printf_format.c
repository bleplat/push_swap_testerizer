/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:29:40 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 18:57:40 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ft_printf_defines.h"
#include "ft_printf_helpers.h"

/*
** ft_printf_format()
**
** Resolve a single rstpart.
** Return ft_strlen of the resulting string.
*/

int			ft_printf_format(t_printf_rstpart *part, va_list ap, int offset)
{
	int		len;

	if ((part->fmt->conversion & 0xFF) == 0)
		ft_printf_format_unknow(part, ap);
	else if ((part->fmt->conversion & 0xFF) == 'n')
		ft_printf_format_n(part, ap, offset);
	else if (ft_strchr(FT_PRINTF_NUMERIC_CHARS, part->fmt->conversion & 0xFF))
		ft_printf_format_integer(part, ap);
	else if (ft_strchr(FT_PRINTF_FLOATS_CHARS, part->fmt->conversion & 0xFF))
		ft_printf_format_float(part, ap);
	else
		ft_printf_format_other(part, ap);
	if (part->fmt && !part->str)
		return (-1);
	if (!part->fmt && !part->str)
		return (0);
	if (ft_printf_adjust_field(part))
		ft_memdel((void**)&(part->fmt));
	len = ft_strlen(part->str);
	return (len);
}
