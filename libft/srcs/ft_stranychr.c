/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stranychr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:48:58 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/28 17:27:05 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_stranychr(const char *s, const char *cs)
{
	const char	*ptn;

	ptn = s;
	while (*ptn != '\0' && !ft_strchr(cs, *ptn))
		ptn++;
	if (ft_strchr(cs, *ptn))
		return ((char *)ptn);
	else
		return (NULL);
}
