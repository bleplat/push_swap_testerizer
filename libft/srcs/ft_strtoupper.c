/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:24:11 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/17 14:39:05 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtoupper(const char *str)
{
	char		*tmp;

	tmp = ft_strdup(str);
	if (tmp == NULL)
		return (NULL);
	str = tmp;
	while (*tmp != '\0')
	{
		*tmp = ft_toupper(*tmp);
		tmp++;
	}
	return ((char*)str);
}
