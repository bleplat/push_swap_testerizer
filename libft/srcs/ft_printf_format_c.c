/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:10:16 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 19:02:12 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ft_printf_defines.h"
#include "ft_printf_helpers.h"

/*
** See ft_printf_format()
*/

int			ft_printf_format_c(t_printf_rstpart *part, va_list ap)
{
	unsigned char	c;

	if (part->fmt->options & FT_PRINTF_OPTION_UPPER)
		part->fmt->conversion |= FT_PRINTF_LENMOD_LONG;
	if (!(part->fmt->conversion & FT_PRINTF_LENMOD_LONG))
	{
		if (!(part->str = ft_strnew(1)))
			return (-1);
		c = (unsigned char)ft_printf_readva_sint(part->fmt->conversion, ap);
		((unsigned char*)part->str)[0] = c;
	}
	else
	{
		if (!(part->str = ft_strnew(4)))
			return (-1);
		ft_wchrtostr((unsigned char*)part->str, ft_va_as_wchar(ap));
	}
	if (part->str[0] == '\0')
	{
		part->str[0] = '@';
		part->at_null = '@';
	}
	return (0);
}
