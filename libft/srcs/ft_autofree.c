/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autofree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:19:50 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/04 20:53:53 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

/*
** Queue a pointer for later deletion.
** On failure, the pointer is freed and NULL is returned,
** otherwise the same pointer is returned.
** Passing NULL to the function do nothing.
*/

void		*ft_autofree(const void *to_free)
{
	if (ft_autofree_pushpop(to_free) != NULL)
	{
		free((void*)to_free);
		return (NULL);
	}
	return ((void*)to_free);
}
