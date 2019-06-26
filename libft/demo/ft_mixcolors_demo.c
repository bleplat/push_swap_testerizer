/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mixcolors_demo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 19:55:14 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/16 20:12:37 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				put_color(int r, int g, int b)
{
	int		rgb;

	rgb = ft_argb(0, r, g, b);
	ft_printf("%1$#Y   {}%1$Y R = %d, G = %d, B = %d\n", rgb, r, g, b);
	return (rgb);
}

int				main(int argc, char **argv)
{
	int		c1;
	int		c2;
	int		c3;

	if (argc != 8)
	{
		ft_printf("Usage: %s   R1 G1 B1   R2 G2 B2   F(%%)\n", argv[0]);
		return (14);
	}
	c1 = put_color(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]));
	c2 = put_color(ft_atoi(argv[4]), ft_atoi(argv[5]), ft_atoi(argv[6]));
	c3 = ft_mixcolors(c1, c2, ft_atoi(argv[7]) / 100.0);
	ft_printf("%1$#Y   {}%1$Y RESULT OF MIX\n", c3);
	return (0);
}
