/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi32check_demo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:55:10 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/05 22:00:05 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				main(int argc, char **argv)
{
	int rst;
	int out;

	if (argc != 2)
	{
		ft_dprintf(2, "Usage: %s [number to atoi]\n", argv[0]);
		return (44);
	}
	out = 0;
	rst = ft_atoi32check(&out, argv[1]);
	if (rst == 0)
		ft_printf("SUCCESS: %d\n", out);
	if (rst == -1)
		ft_printf("FAILURE: INVALID CHARACTER\n");
	if (rst == -2)
		ft_printf("FAILURE: OUT OF INT32 LIMITS\n");
	return (rst);
}
