/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_demo_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 22:16:28 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/27 22:46:38 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int				main(int argc, char **argv)
{
	int x;

	(void)argc;
	(void)argv;
	x = 0;
	while (x <= 255)
	{
		if (x != 0 && x % 16 == 0)
			ft_printf("\n");
		ft_printf("%y%1$4d", x);
		x++;
	}
	return (0);
}
