/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:29:00 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/13 16:09:32 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t		i1;
	size_t		i2;

	i1 = 0;
	while (s1[i1] != '\0' && i1 < size)
		i1++;
	if (s1[i1] != '\0')
		return (size + ft_strlen(s2));
	i2 = 0;
	while (i1 + i2 < size - 1 && s2[i2] != '\0')
	{
		s1[i1 + i2] = s2[i2];
		i2++;
	}
	s1[i1 + i2] = '\0';
	return (i1 + ft_strlen(s2));
}
