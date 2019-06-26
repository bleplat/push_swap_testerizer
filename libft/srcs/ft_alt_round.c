/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alt_round.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:03:52 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/12 18:31:44 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double		ft_alt_round(long double d, unsigned int precision)
{
	int				digit;
	int				next_digit;

	digit = ((long long int)(d * ft_llpow(10, precision + 0))) % 10;
	next_digit = ((long long int)(d * ft_llpow(10, precision + 1))) % 10;
	if (next_digit < 5)
		d += 0;
	else if (next_digit > 5)
		d += (1.0 / ft_llpow(10, precision));
	else if (!(digit % 2))
		d += (1.0 / ft_llpow(10, precision));
	return (d);
}
