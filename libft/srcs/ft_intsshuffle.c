/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsshuffle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:38:52 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/05 16:46:15 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_intsshuffle(int *array, int count)
{
	int		i_int;
	int		new_index;
	int		swap;

	i_int = count - 1;
	while (i_int > 0)
	{
		new_index = ((ft_urandom() + i_int) % i_int);
		swap = array[new_index];
		array[new_index] = array[i_int];
		array[i_int] = swap;
		i_int--;
	}
}
