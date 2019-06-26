/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mixcolors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 19:48:14 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/16 19:54:57 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Mix two colors together, with ratio rate.
** r = 0.0 means 'only c0' and r = 1.0 means 'only c1'.
*/

int				ft_mixcolors(int c0, int c1, double rate)
{
	int		a;
	int		r;
	int		g;
	int		b;

	a = ((c0 >> 24) & 0xFF) * (1.0 - rate) + ((c1 >> 24) & 0xFF) * (rate);
	r = ((c0 >> 16) & 0xFF) * (1.0 - rate) + ((c1 >> 16) & 0xFF) * (rate);
	g = ((c0 >> 8) & 0xFF) * (1.0 - rate) + ((c1 >> 8) & 0xFF) * (rate);
	b = ((c0 >> 0) & 0xFF) * (1.0 - rate) + ((c1 >> 0) & 0xFF) * (rate);
	return (ft_argb(a, r, g, b));
}
