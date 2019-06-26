/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkfolow_demo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:37:20 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/10 18:27:39 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

int				main(int argc, char **argv)
{
	char		*result;

	if (argc != 2)
	{
		ft_printf("Usage: %s LINK\n", argv[0]);
		return (127);
	}
	result = ft_linkfolow(argv[1]);
	ft_printf("%s -> %s\n", argv[1], result);
	free(result);
	return (0);
}
