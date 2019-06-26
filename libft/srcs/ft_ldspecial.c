/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldspecial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:23:12 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/27 19:57:20 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return a string representing the special value of a long double 'd'.
** Output NULL if malloc fail.
** Return 0 if d is not 'inf', '-inf' or 'nan'.
*/

int					ft_ldspecial(long double d, char **may_out)
{
	if (d == 1.0 / 0.0)
	{
		*may_out = ft_strdup("inf");
		return (1);
	}
	if (d == -1.0 / 0.0)
	{
		*may_out = ft_strdup("-inf");
		return (1);
	}
	if (d != d)
	{
		*may_out = ft_strdup("nan");
		return (1);
	}
	return (0);
}
