/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:00:14 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/13 16:13:06 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	const char	*ptn;

	if (c < 0 || c > 255)
		return (NULL);
	ptn = s;
	while (*ptn != '\0')
		ptn++;
	while (ptn > s && *ptn != c)
		ptn--;
	if (*ptn == c)
		return ((char *)ptn);
	else
		return (NULL);
}
