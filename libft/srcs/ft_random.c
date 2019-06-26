/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:44:05 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/05 15:12:56 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "libft.h"

int					ft_random(void)
{
	int			fd;
	int			rst;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
		return (0);
	rst = 0;
	read(fd, (char*)(&rst), sizeof(rst));
	close(fd);
	return (rst);
}
