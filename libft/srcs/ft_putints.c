/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:51:15 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/05 18:22:39 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putints(const int *array, int count, const char *sep)
{
	int		i_int;

	i_int = 0;
	if (sep == NULL)
		sep = " ";
	while (i_int < count)
	{
		if (i_int != 0)
			ft_putstr(sep);
		ft_putnbr(array[i_int]);
		i_int++;
	}
}
