/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 13:22:34 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/17 13:30:58 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, size_t n)
{
	char	*new_str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	new_str = ft_strnew(n);
	if (new_str != NULL)
	{
		i = 0;
		while (i < len && i < n)
		{
			new_str[i] = s1[i];
			i++;
		}
	}
	return (new_str);
}
