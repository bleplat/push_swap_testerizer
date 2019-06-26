/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldsign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:30:25 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/27 20:18:03 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Get the sign of a long double.
** Return -1.0 or 1.0, case of +0.0 and -0.0 is handled.
*/

long double			ft_ldsign(long double d)
{
	float				mzero_d;
	long double			sign;

	mzero_d = ((float)d * 0.0f) / 2000.0f;
	sign = (d < 0.0l || (d == -0.0 && (*((int32_t*)(&mzero_d)) >> 31) & 1)) ?
		-1.0 : 1.0;
	return (sign);
}
