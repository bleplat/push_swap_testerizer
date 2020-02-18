/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmo_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:09:05 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/16 16:44:17 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdlib.h>

#include "libftmo.h"

/*
** ftmo_libc_malloc:
**
** Real malloc function.
*/

void		*ftmo_libc_malloc(size_t sz)
{
	void		*(*libc_malloc)(size_t);

	libc_malloc = dlsym(RTLD_NEXT, "malloc");
	if (!libc_malloc)
		return (NULL);
	return (libc_malloc(sz));
}

/*
** malloc:
**
** Overload the malloc function in the libc.
*/

void		*malloc(size_t sz)
{
	static long		call_count = -1;
	static int		in_progress = 0;
	int				should_malloc_succeed;
	void			*malloced;

	if (in_progress)
		return (ftmo_libc_malloc(sz));
	in_progress = 1;
	call_count++;
	if (call_count == 0)
		if (ftmo_firstcall() != 0)
		{
			ftmo_log(-1, "Internal error while initializing");
			return (ftmo_libc_malloc(sz));
		}
	should_malloc_succeed = ftmo_should_malloc_succeed(call_count);
	if (should_malloc_succeed)
		malloced = ftmo_libc_malloc(sz);
	else
		malloced = (void*)0;
	ftmo_track(FTMO_TRACK_MALLOC, malloced, sz, call_count);
	in_progress = 0;
	return (malloced);
}
