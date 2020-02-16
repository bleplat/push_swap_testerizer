/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline_demo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:07:17 by bleplat           #+#    #+#             */
/*   Updated: 2019/05/16 20:07:19 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include "libft.h"
#include "libft_readline.h"

void			loop(int fd)
{
	int		color;
	char	*line;
	int		rst;

	while ((rst = ft_readline(fd, &line)) > 0)
	{
		color = (ft_urandom() + 256) % 256;
		ft_printf("%y(%d) %s", color, rst, line);
	}
	if (rst < 0)
		ft_printf("{red}{bold}{italic}rst == %d\n", rst);
	ft_readline(fd, (void*)0);
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
		ft_dprintf(2, "{red}ERROR{}\n");
		return (1);
	}
	loop(fd);
	if (fd > 0)
		close(fd);
	return (0);
}
