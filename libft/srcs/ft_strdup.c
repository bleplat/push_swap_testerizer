/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:18:46 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/08 14:03:42 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*new_str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	new_str = ft_strnew(len);
	if (new_str != NULL)
	{
		i = 0;
		while (i < len)
		{
			new_str[i] = s1[i];
			i++;
		}
	}
	return (new_str);
}
