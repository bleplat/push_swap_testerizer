/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:45:08 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/03 19:24:51 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

static int		ft_put4char(char to_put[5], int fd)
{
	int		len;

	len = ft_strlen(to_put);
	write(fd, to_put, ft_max(1, len));
	return (len);
}

/*
** Print an Unicode character and return the count of bytes put.
*/

int				ft_putwchar_fd(wchar_t chr, int fd)
{
	if (chr < 0x80)
		return (ft_put4char((char[5]){chr, '\0', '\0', '\0', 0}, fd));
	else if (chr < 0x800)
	{
		return (ft_put4char((char[5]){((chr >> 6) & 0x1F) | 0xC0,
					((chr >> 0) & 0x3F) | 0x80,
					'\0',
					'\0', 0}, fd));
	}
	else if (chr < 0x10000)
	{
		return (ft_put4char((char[5]){((chr >> 12) & 0xF) | 0xE0,
					((chr >> 6) & 0x3F) | 0x80,
					((chr >> 0) & 0x3F) | 0x80,
					'\0', 0}, fd));
	}
	else if (chr < 0x110000)
	{
		return (ft_put4char((char[5]){((chr >> 18) & 0x7) | 0xF0,
					((chr >> 12) & 0x3F) | 0x80,
					((chr >> 6) & 0x3F) | 0x80,
					((chr >> 0) & 0x3F) | 0x80, 0}, fd));
	}
	else
		return (0);
}
