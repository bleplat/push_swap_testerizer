/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_urandom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:55:05 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/05 21:11:49 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_urandom(void)
{
	int		rst;

	rst = ft_random();
	return ((unsigned int)((rst > 0) ? rst : -rst));
}