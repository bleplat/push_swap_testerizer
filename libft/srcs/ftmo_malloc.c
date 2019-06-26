/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmo_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:09:05 by bleplat           #+#    #+#             */
/*   Updated: 2019/05/14 16:56:33 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdlib.h>

#include "libftmo.h"

/*
** malloc:
**
** Overload the malloc function in the libc.
*/

void		*malloc(size_t sz)
{
	void		*(*libc_malloc)(size_t);
	int			choice;
	void		*malloced;

	choice = ftmo_choice();
	if (choice)
		malloced = (void*)0;
	else
	{
		libc_malloc = dlsym(RTLD_NEXT, "malloc");
		malloced = libc_malloc(sz);
	}
	ftmo_log(FTMO_FUNC_MALLOC, sz, malloced);
	return (malloced);
}

/*
** free:
**
** Overload the free function in the libc.
*/

void		free(void *ptr)
{
	void		(*libc_free)(void *);

	libc_free = dlsym(RTLD_NEXT, "free");
	libc_free(ptr);
	ftmo_log(FTMO_FUNC_FREE, 0, ptr);
}
