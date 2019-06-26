/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:41:56 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/26 18:30:40 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_needs(unsigned long long int n, int base)
{
	int		len;

	len = 0;
	while (n >= (unsigned int)base)
	{
		len++;
		n /= base;
	}
	len++;
	return (len);
}

char		*ft_ulltoa_basestr(unsigned long long int n, char *base_str)
{
	long long int			base;
	char					*new_str;
	int						len;
	int						i_c;

	base = ft_strlen(base_str);
	len = len_needs(n, base);
	new_str = ft_strnew(len);
	if (new_str == NULL)
		return (NULL);
	i_c = len - 1;
	while (n >= (unsigned long long)base)
	{
		new_str[i_c] = base_str[n % base];
		n /= base;
		i_c--;
	}
	new_str[i_c] = base_str[n % base];
	return (new_str);
}
