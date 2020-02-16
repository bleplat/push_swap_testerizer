/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_rstparts_get.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:48:13 by bleplat           #+#    #+#             */
/*   Updated: 2020/01/15 14:47:55 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ft_printf_defines.h"
#include "ft_printf_helpers.h"

/*
** ft_printf_rstparts_autoindices()
**
** Set all auto iap elements in the given parts. This mean everywhere
** a va_list index is 0, it is set to the next one after the previous one.
*/

static void	ft_printf_rstparts_autoindices(t_printf_rstpart *parts, int pcount)
{
	int		i_part;
	int		next_iap;

	next_iap = 1;
	i_part = 0;
	while (i_part < pcount)
	{
		if (parts[i_part].str == NULL && parts[i_part].fmt != NULL)
		{
			if (parts[i_part].fmt->fieldw_iap == 0)
				parts[i_part].fmt->fieldw_iap = next_iap;
			if (parts[i_part].fmt->fieldw_iap > 0)
				next_iap = parts[i_part].fmt->fieldw_iap + 1;
			if (parts[i_part].fmt->precision_iap == 0)
				parts[i_part].fmt->precision_iap = next_iap;
			if (parts[i_part].fmt->precision_iap > 0)
				next_iap = parts[i_part].fmt->precision_iap + 1;
			if (parts[i_part].fmt->iap == 0)
				parts[i_part].fmt->iap = next_iap;
			if (parts[i_part].fmt->iap > 0 && ft_strchr(FT_PRINTF_CONV_CHARS,
										(char)parts[i_part].fmt->conversion))
				next_iap = parts[i_part].fmt->iap + 1;
		}
		i_part++;
	}
}

/*
** ft_printf_getformatparts()
**
** Split a format string into an array of t_printf_part.
*/

t_array		*ft_printf_rstparts_get(const char *fmt)
{
	t_array				*array;
	t_printf_rstpart	*new_item;

	array = ft_array_new(sizeof(t_printf_rstpart), 8);
	if (!array)
		return (NULL);
	while (*fmt != '\0')
	{
		if (!(new_item = ft_array_newitem(array)))
		{
			ft_printf_rstparts_clean(&array);
			return (NULL);
		}
		if (ft_printf_nextrstpart((char**)&fmt, (char*)fmt, new_item) < 0)
		{
			ft_printf_rstparts_clean(&array);
			return (NULL);
		}
	}
	ft_printf_rstparts_autoindices(array->items, array->item_count);
	return (array);
}
