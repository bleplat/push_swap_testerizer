/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:01:50 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/04 14:51:12 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "libft_array.h"

t_array			*ft_array_new(int item_size, int item_capacity)
{
	t_array		*to_return;

	to_return = ft_memalloc(sizeof(t_array));
	if (!to_return)
		return (NULL);
	to_return->item_size = item_size;
	if (item_capacity == 0 || ft_array_reserve(to_return, item_capacity))
	{
		free(to_return);
		return (NULL);
	}
	return (to_return);
}
