/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:48:58 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/13 16:12:40 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	const char	*ptn;

	if (c < 0 || c > 255)
		return (NULL);
	ptn = s;
	while (*ptn != '\0' && *ptn != c)
		ptn++;
	if (*ptn == c)
		return ((char *)ptn);
	else
		return (NULL);
}
