/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:18:39 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/17 14:40:02 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtolower(const char *str)
{
	char		*tmp;

	tmp = ft_strdup(str);
	if (tmp == NULL)
		return (NULL);
	str = tmp;
	while (*tmp != '\0')
	{
		*tmp = ft_tolower(*tmp);
		tmp++;
	}
	return ((char*)str);
}
