/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:32:58 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/13 11:51:29 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*new_str;

	if (s == NULL)
		return (NULL);
	new_str = ft_strnew(len);
	if (new_str != NULL)
	{
		ft_strncpy(new_str, s + start, len);
	}
	return (new_str);
}
