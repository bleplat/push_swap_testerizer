/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:12:03 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/04 14:54:51 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		i++;
	}
	if (i == n)
		return (0);
	else
		return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
