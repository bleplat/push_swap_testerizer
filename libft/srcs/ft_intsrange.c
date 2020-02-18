/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsrange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:25:02 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/17 20:44:37 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

/*
** create an array of count ints from min, with a given step.
** Array is terminated by 0.
** Return the array or NULL on error (if malloc failed).
*/

int				*ft_intsrange(int min, int count, int step)
{
	int		*to_return;
	int		i_int;

	if (!(to_return = malloc(sizeof(int) * (count + 1))))
		return (NULL);
	i_int = 0;
	while (i_int < count)
	{
		to_return[i_int] = min + (i_int * step);
		i_int++;
	}
	to_return[count] = 0;
	return (to_return);
}

/*
** Create a range of int with a specific given operation.
*/

int				*ft_intsrangeop(int min, int count, int step, char op)
{
	int		*to_return;
	int		i_int;

	if ((op == '%' || op == '/') && step == 0)
		return (NULL);
	if (!(to_return = malloc(sizeof(int) * (count + 1))))
		return (NULL);
	i_int = 0;
	while (i_int < count)
	{
		to_return[i_int] = min;
		if (op == '*')
			min = min * step;
		else if (op == '/')
			min = min / step;
		else if (op == '%')
			min = min % step;
		else if (op == '-')
			min = min - step;
		else
			min = min + step;
		i_int++;
	}
	to_return[count] = 0;
	return (to_return);
}
