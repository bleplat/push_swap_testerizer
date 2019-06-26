/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:51:15 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/13 20:08:07 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	should_skip(char c)
{
	return (((unsigned char)c <= ' ') && c != '\0' && c != 27);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		total;

	i = 0;
	while (should_skip(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	total = 0;
	while (ft_isdigit(str[i]))
	{
		total = (total * 10) + (str[i] - '0');
		i++;
	}
	return (total * sign);
}
