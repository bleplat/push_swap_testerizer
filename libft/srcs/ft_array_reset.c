/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_reset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:04:15 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/04 14:51:37 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "libft_array.h"

int				ft_array_reset(t_array *a, int item_count)
{
	free(a->items);
	a->item_capacity = 0;
	a->item_count = 0;
	return (ft_array_reserve(a, item_count));
}
