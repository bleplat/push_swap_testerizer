/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_va_list_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:10:16 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 18:57:11 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ft_printf_defines.h"
#include "ft_printf_helpers.h"

/*
** ft_printf_getmaxap()
**
** Return the maximum va_list index used in given printf rstparts.
*/

int			ft_printf_getmaxap(t_printf_rstpart *parts, int pcount)
{
	int		i_rstpart;
	int		max_ap;

	max_ap = 0;
	i_rstpart = 0;
	while (i_rstpart < pcount)
	{
		if (parts[i_rstpart].fmt != NULL)
		{
			if (max_ap < parts[i_rstpart].fmt->iap)
				max_ap = parts[i_rstpart].fmt->iap;
			if (max_ap < parts[i_rstpart].fmt->fieldw_iap)
				max_ap = parts[i_rstpart].fmt->fieldw_iap;
			if (max_ap < parts[i_rstpart].fmt->precision_iap)
				max_ap = parts[i_rstpart].fmt->precision_iap;
		}
		i_rstpart++;
	}
	return (max_ap);
}

/*
** ft_printf_getapconv()
**
** Return the conversion used by the first rstpart using this va_list index.
** Return a default int conversion by default.
*/

int			ft_printf_getapconv(int i_ap, t_printf_rstpart *parts, int pcount)
{
	int		i_rstpart;

	i_rstpart = 0;
	while (i_rstpart < pcount)
	{
		if (parts[i_rstpart].fmt != NULL && parts[i_rstpart].fmt->iap == i_ap)
			return (parts[i_rstpart].fmt->conversion);
		i_rstpart++;
	}
	return (FT_PRINTF_LENMOD_DEFAULT | 'd');
}

/*
** ft_printf_apvect()
**
** Create a vector of va_list containers to get a true list of va_list,
** not just that weird thing.
** You still need to copy items before using it, to not break
** the array.
** Item 0 is filled with zeros and should not be used. this mean the array
** have one additional item inside. This was done to keep indices logic
** because they start at 1.
** return -1 on error;
*/

int			ft_printf_apvect(t_va_list_c **apcs, t_array *parts_a, va_list ap)
{
	int		conv;
	int		i_ap;
	int		max_ap;

	max_ap = ft_printf_getmaxap(parts_a->items, parts_a->item_count);
	if (!(*apcs = (t_va_list_c*)malloc(sizeof(t_va_list_c) * (max_ap + 1))))
		return (-1);
	ft_bzero(*apcs, sizeof(t_va_list_c) * 1);
	if (max_ap == 0)
		return (0);
	va_copy((*apcs)[1].ap, ap);
	i_ap = 2;
	while (i_ap <= max_ap)
	{
		va_copy((*apcs)[i_ap].ap, (*apcs)[i_ap - 1].ap);
		conv = ft_printf_getapconv(i_ap - 1, parts_a->items,
				parts_a->item_count);
		ft_printf_skipva(conv, &((*apcs)[i_ap]));
		i_ap++;
	}
	return (max_ap);
}

/*
** ft_printf_endapvect()
**
** Free a vector of va_list and end items from 1 to 'ap_max' included.
*/

void		ft_printf_endapvect(t_va_list_c **apcs, int ap_max)
{
	int		i_ap;

	i_ap = 1;
	while (i_ap <= ap_max)
	{
		va_end((*apcs)[i_ap].ap);
		i_ap++;
	}
	ft_memdel((void**)apcs);
}
