/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:06:52 by bleplat           #+#    #+#             */
/*   Updated: 2019/05/02 18:24:30 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Rotate ints in an ints array.
*/

void			ft_intsrot(int *array, int count, int rotation)
{
	int		swp;

	if (rotation < 0)
	{
		while (rotation != 0)
		{
			swp = array[0];
			ft_memmove(array, array + 1, (count - 1) * sizeof(int));
			array[count - 1] = swp;
			rotation++;
		}
	}
	else
	{
		while (rotation != 0)
		{
			swp = array[count - 1];
			ft_memmove(array + 1, array, (count - 1) * sizeof(int));
			array[0] = swp;
			rotation--;
		}
	}
}
