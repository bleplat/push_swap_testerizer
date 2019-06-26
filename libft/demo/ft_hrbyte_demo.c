/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hrbyte_demo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:06:44 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/10 20:23:20 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			main(int argc, char **argv)
{
	int			bytes;
	int			step;
	char		hr[5];

	bytes = (argc > 1) ? ft_atoi(argv[1]) : 0;
	step = (argc > 2) ? ft_atoi(argv[2]) : 1;
	while (1)
	{
		ft_hrbytes(hr, bytes);
		ft_printf("{red}%12d        {green}%s{black}", bytes, hr);
		ft_pause();
		bytes += step;
	}
	return (0);
}
