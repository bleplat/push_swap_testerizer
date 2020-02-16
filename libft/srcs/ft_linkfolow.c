/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkfolow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 09:46:47 by bleplat           #+#    #+#             */
/*   Updated: 2020/01/15 14:44:52 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#include "libft.h"

static int		increase_len(char **dst, int *len)
{
	if (*dst)
		free(*dst);
	if (*len > 1024 * 1024)
		return (-2);
	*len = (*len) * 2;
	*dst = ft_strnew(*len);
	return ((*dst) ? 0 : -1);
}

/*
** Folow a symbolic link, returning its content.
** On error, return NULL and set errno.
*/

char			*ft_linkfolow(const char *link)
{
	char		*dst;
	int			dst_len;
	int			readed;

	errno = 0;
	dst = NULL;
	dst_len = 32 / 2;
	while (increase_len(&dst, &dst_len) == 0)
	{
		readed = readlink(link, dst, dst_len);
		if (readed < 0)
		{
			ft_free0(dst);
			return (NULL);
		}
		if (readed < dst_len)
			return (dst);
	}
	errno = ENOMEM;
	return (NULL);
}
