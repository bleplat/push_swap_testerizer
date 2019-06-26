/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsnshuffle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:38:52 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/05 20:51:20 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_intsnshuffle(int *array, int count, int shuffles_count)
{
	int		i_shuffle;
	int		i_int1;
	int		i_int2;
	int		swap;

	i_shuffle = 0;
	while (i_shuffle < shuffles_count)
	{
		i_int1 = ((ft_urandom() + count) % count);
		i_int2 = ((ft_urandom() + count) % count);
		swap = array[i_int2];
		array[i_int2] = array[i_int1];
		array[i_int1] = swap;
		i_shuffle++;
	}
}
