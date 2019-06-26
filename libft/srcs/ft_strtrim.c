/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:09:14 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/08 17:23:17 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_whitespace(char c)
{
	return ((c == ' ' || c == '\t' || c == '\n') ? 1 : 0);
}

char			*ft_strtrim(char const *s)
{
	int		len;
	char	*start;
	char	*new_str;

	if (s == NULL)
		return (NULL);
	start = (char *)s;
	while (*start != 0 && is_whitespace(*start))
		start++;
	len = 0;
	while (start[len] != 0)
		len++;
	while (len >= 0 && (is_whitespace(start[len]) == 1 || start[len] == 0))
		len--;
	len++;
	new_str = ft_strnew(len);
	if (new_str == NULL)
		return (NULL);
	ft_strncpy(new_str, start, len);
	return (new_str);
}
