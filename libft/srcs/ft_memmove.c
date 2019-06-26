/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:20:42 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/13 16:10:45 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (src <= dst)
			((unsigned char *)dst)[len - 1 - i] =
				((unsigned char *)src)[len - 1 - i];
		else
			((unsigned char *)dst)[i] =
				((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
