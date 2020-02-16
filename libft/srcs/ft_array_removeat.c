/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_removeat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:04:50 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/16 14:12:45 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Remove an item from an t_array.
** UNTESTED!!!
*/

void						ft_array_removeat(t_array *a, int index)
{
	void	*dst;
	void	*src;

	if (a->item_count == 0 || index > a->item_count - 1 || index < 0)
		return ;
	dst = a->items + a->item_size * index;
	src = dst + a->item_size;
	ft_memmove(dst, src, a->item_size * (a->item_count - index - 1));
	a->item_count--;
}
