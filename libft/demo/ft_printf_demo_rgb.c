/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_demo_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 22:16:28 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/27 22:52:45 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int				main(int argc, char **argv)
{
	int r;
	int g;
	int b;

	(void)argc;
	(void)argv;
	if (argc < 4)
		ft_printf("Please put R G and B args.");
	else
	{
		r = ft_atoi(argv[1]);
		g = ft_atoi(argv[2]);
		b = ft_atoi(argv[3]);
		ft_printf("{red}R = %d{}, {green}G = %d{}, {blue}B = %d{}:\n",
				r,
				g,
				b);
		ft_printf("%1$YYour {black}%1$#YColor{}\n", (r << 16) | (g << 8) | (b));
	}
	return (0);
}
