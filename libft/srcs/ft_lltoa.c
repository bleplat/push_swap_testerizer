/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:41:56 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/13 17:27:15 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_needs(long long int n)
{
	int		len;

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

char		*ft_lltoa(long long int n)
{
	char		*new_str;
	int			len;
	int			i_c;

	if ((t_ullint)n == (t_ullint)(-9223372036854775807 - 1))
		return (ft_strdup("-9223372036854775808"));
	len = len_needs(n);
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
