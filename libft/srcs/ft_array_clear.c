/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:01:27 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/04 14:50:39 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_array.h"

void			ft_array_clear(t_array *array)
{
	ft_bzero(array->items, array->item_count * array->item_size);
	array->item_count = 0;
}
