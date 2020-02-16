/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_demo_8ints_asprintf.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:07:02 by bleplat           #+#    #+#             */
/*   Updated: 2019/05/16 20:07:03 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "ft_printf.h"

int				main(int argc, char **argv)
{
	int		x;
	char	*dst;

	x = -99;
	dst = (void*)0;
	if (argc > 10)
		ft_printf("You can use up to 8 integers as args.\n");
	else
		x = ft_asprintf(
			&dst,
			(argc > 1) ? argv[1] : "Enter an int32 format stings and args\n",
			(argc > 2) ? ft_atoi(argv[2]) : 0,
			(argc > 3) ? ft_atoi(argv[3]) : 0,
			(argc > 4) ? ft_atoi(argv[4]) : 0,
			(argc > 5) ? ft_atoi(argv[5]) : 0,
			(argc > 6) ? ft_atoi(argv[6]) : 0,
			(argc > 7) ? ft_atoi(argv[7]) : 0,
			(argc > 8) ? ft_atoi(argv[8]) : 0,
			(argc > 9) ? ft_atoi(argv[9]) : 0);
	ft_printf("got \"%s\"\n", dst);
	free(dst);
	return (x);
}
