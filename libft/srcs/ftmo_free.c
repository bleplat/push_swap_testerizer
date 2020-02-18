/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmo_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:09:05 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/16 16:44:28 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdlib.h>

#include "libftmo.h"

/*
** ftmo_libc_free:
**
** Real call to free.
*/

void		ftmo_libc_free(void *ptr)
{
	void		(*libc_free)(void *);

	libc_free = dlsym(RTLD_NEXT, "free");
	if (!libc_free)
		return ;
	libc_free(ptr);
}

/*
** free:
**
** Overload the free function in the libc.
*/

void		free(void *ptr)
{
	static int		in_progress = 0;

	if (in_progress)
	{
		ftmo_libc_free(ptr);
		return ;
	}
	in_progress = 1;
	ftmo_libc_free(ptr);
	ftmo_track(FTMO_TRACK_FREE, ptr, 0, -1);
	in_progress = 0;
}
