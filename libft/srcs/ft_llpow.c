/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:54:11 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/13 19:32:38 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llint			ft_llpow(t_llint nb, unsigned int p)
{
	t_llint		total;

	total = 1;
	while (p > 0)
	{
		total *= nb;
		p--;
	}
	return (total);
}
