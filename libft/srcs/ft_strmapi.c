/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:20:17 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/07 16:22:32 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			new_str[i] = f(i, s[i]);
			i++;
		}
	}
	return (new_str);
}
