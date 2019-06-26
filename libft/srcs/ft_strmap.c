/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:08:29 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/07 16:23:15 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	size_t	len;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	new_str = ft_strnew(len);
	if (new_str != NULL)
	{
		i = 0;
		while (i < len)
		{
			new_str[i] = f(s[i]);
			i++;
		}
	}
	return (new_str);
}
