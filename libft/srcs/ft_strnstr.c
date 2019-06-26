/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:06:23 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/04 14:56:58 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		i_need;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		i_need = 0;
		while ((i + i_need) < len && haystack[i + i_need] == needle[i_need])
		{
			if (needle[i_need + 1] == '\0')
				return ((char *)(haystack + i));
			i_need++;
		}
		i++;
	}
	return (NULL);
}
