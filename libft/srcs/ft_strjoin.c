/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:40:32 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/13 16:47:32 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len_sum;
	char	*new_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_sum = ft_strlen(s1) + ft_strlen(s2);
	new_str = ft_strnew(len_sum);
	if (new_str == NULL)
		return (NULL);
	ft_strcpy(new_str, s1);
	ft_strcat(new_str, s2);
	return (new_str);
}
