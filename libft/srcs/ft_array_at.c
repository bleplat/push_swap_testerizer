/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:32:51 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/04 14:50:13 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_array.h"

void			*ft_array_at(t_array *a, int index)
{
	if (index < 0 || index >= a->item_count)
		return (NULL);
	return (a->items + (a->item_size * index));
}
