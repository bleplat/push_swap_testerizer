/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:19:55 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/14 03:40:38 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Put a big hex number.
**
** TODO: /!\ FUNCTION MADE IN A HURRY!
*/

void	ft_putxnbr_fd(unsigned long long n, int fd)
{
	if (n >= 16)
		ft_putxnbr_fd(n / 16, fd);
	ft_putchar_fd("0123456789abcdef"[n % 16], fd);
}
