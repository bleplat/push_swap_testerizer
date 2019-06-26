/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:02:02 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/15 16:02:11 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void		*newly_allocated;

	newly_allocated = NULL;
	newly_allocated = malloc(size);
	if (newly_allocated != NULL)
		ft_bzero(newly_allocated, size);
	return (newly_allocated);
}
