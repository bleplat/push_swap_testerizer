/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:13:54 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 19:01:40 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ft_printf_defines.h"
#include "ft_printf_types.h"

/*
** See ft_printf_format()
*/

int			ft_printf_format_s(t_printf_rstpart *part, va_list ap)
{
	void	*s_ptr;

	s_ptr = ft_va_as_ptr(ap);
	if (s_ptr == NULL)
	{
		part->str = ft_strdup("(null)");
		return ((part->str) ? 0 : -1);
	}
	if (part->fmt->options & FT_PRINTF_OPTION_UPPER)
		part->fmt->conversion |= FT_PRINTF_LENMOD_LONG;
	if (!(part->fmt->options & FT_PRINTF_OPTION_UPPER))
	{
		if (part->fmt->precision_iap == FT_PRINTF_IAP_UNUSED)
			part->str = ft_strdup(s_ptr);
		else
			part->str = ft_strsub(s_ptr, 0, part->fmt->precision);
	}
	else if (part->fmt->precision_iap == FT_PRINTF_IAP_UNUSED)
		part->str = (char*)ft_wstrtostr((wchar_t*)s_ptr, -1);
	else
		part->str = (char*)ft_wstrtostr((wchar_t*)s_ptr,
			ft_max(0, part->fmt->precision));
	return ((part->str) ? 0 : -1);
}
