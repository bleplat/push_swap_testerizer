/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_newitem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:22:49 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/04 14:51:22 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_array.h"

void		*ft_array_newitem(t_array *a)
{
	if (a->item_count >= a->item_capacity)
		if (ft_array_reserve(a, ft_max(1, a->item_count * 2)))
			return (NULL);
	a->item_count += 1;
	return (a->items + (a->item_size * (a->item_count - 1)));
}
