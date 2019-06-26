/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_urandom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:55:05 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/05 15:18:34 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_ullint		ft_ullrandom(void)
{
	t_llint		rst;

	rst = ft_llrandom();
	return ((t_ullint)((rst > 0) ? rst : -rst));
}
