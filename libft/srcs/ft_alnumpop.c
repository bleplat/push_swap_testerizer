/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alnumpop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:11:43 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/27 19:55:07 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Check that 'source' is beginning with 's2' and that a folowing char in
** source is not an ascii char (that it is a separator).
** Return 0 if 's2' is not at the beginning of 'source', len of 's2' otherwise.
*/

int		ft_alnumpop(const char *source, const char *s2)
{
	int			len;

	len = 0;
	while (*source == *s2 || (!ft_isalnum(*source) && !ft_isalnum(*s2)))
	{
		if (*source == '\0' || !ft_isalnum(*source))
			return (len);
		len++;
		source++;
		s2++;
	}
	return (0);
}
