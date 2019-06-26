/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_reserve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:11:42 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/04 14:51:29 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_array.h"

int			ft_array_reserve(t_array *a, int item_capacity)
{
	size_t		bsize;

	if (item_capacity < a->item_count)
		return (1);
	bsize = a->item_capacity * a->item_size;
	if (ft_memrealloc(&(a->items), &bsize, item_capacity * a->item_size))
		return (1);
	a->item_capacity = item_capacity;
	return (0);
}
