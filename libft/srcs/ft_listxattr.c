/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listxattr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:38:56 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/10 19:23:16 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <sys/xattr.h>

#include "libft.h"

/*
** Fill a list of NULL terminated strings in a single buffer, allocating it.
** Return the size of the buffer.
** On error, return -1 and set errno.
*/

int				ft_listxattr(char **out, const char *path, int options)
{
	int			len;

	errno = 0;
	if (out)
		*out = NULL;
	len = listxattr(path, NULL, 0, options);
	if (len <= 0 || !out)
		return (len);
	if (!(*out = malloc(len)))
	{
		errno = ENOMEM;
		return (-1);
	}
	len = listxattr(path, *out, len, options);
	if (len < 0)
	{
		free((void*)*out);
		*out = NULL;
	}
	return (len);
}
