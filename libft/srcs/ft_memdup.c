/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:42:39 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/14 18:49:51 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memdup(const void *s1, size_t size)
{
	size_t	i;
	void	*new_mem;

	new_mem = ft_memalloc(size);
	if (new_mem != NULL)
	{
		i = 0;
		while (i < size)
		{
			((char *)new_mem)[i] = ((const char *)s1)[i];
			i++;
		}
	}
	return (new_mem);
}
