/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:46:29 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/07 17:04:06 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_strlen_needs(int n)
{
	int		len;

	if (n == -2147483648)
		return (11);
	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	len++;
	return (len);
}

char		*ft_itoa(int n)
{
	char		*new_str;
	int			len;
	int			i_c;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_itoa_strlen_needs(n);
	new_str = ft_strnew(len);
	if (new_str == NULL)
		return (new_str);
	if (n < 0)
	{
		new_str[0] = '-';
		n *= -1;
	}
	i_c = len - 1;
	while (n > 9)
	{
		new_str[i_c] = '0' + (n % 10);
		n /= 10;
		i_c--;
	}
	new_str[i_c] = '0' + (n % 10);
	return (new_str);
}
