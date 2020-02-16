/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readtonl_demo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:07:34 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/16 13:52:54 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "libft.h"

int				loop(int fd)
{
	char		*line;
	int			rst;

	while ((rst = ft_readtonl(fd, &line, 32)) >= 0)
	{
		ft_printf("[rst == %2d] %s", rst, line);
		if (line && ft_strcmp(line, "exit\n") == 0)
			return (ft_free0(line));
		if (line && ft_strcmp(line, "help\n") == 0)
		{
			ft_printf("{green}Exit with 'exit'\n");
			ft_printf("{cyan}Max line lenght is 32, try it!\n");
		}
		ft_free0(line);
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
