/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alnumcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:11:43 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/23 12:32:12 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_alnumcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 || (!ft_isalnum(*s1) && !ft_isalnum(*s2)))
	{
		if (*s1 == '\0' || !ft_isalnum(*s1))
			return (0);
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
