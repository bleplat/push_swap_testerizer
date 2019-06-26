/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readtonl_demo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 22:31:09 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/04 23:16:14 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "libft.h"

int				loop(int fd)
{
	char		*line;
	int			rst;

	while ((rst = ft_readtonl(fd, &line, 16)) >= 0)
	{
		ft_printf("[rst == %2d] %s", rst, line);
	}
	ft_printf("[rst == %2d]", rst);
	return (0);
}

int				main(int argc, char **argv)
{
	int		fd;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (argc > 2 || fd < 0)
	{
		ft_dprintf(2, "{red}ERROR\n");
		return (1);
	}
	loop(fd);
	if (fd > 0)
		close(fd);
	return (0);
}
