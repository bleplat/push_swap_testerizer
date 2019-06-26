/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:43:20 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/03 19:27:15 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putwstr_fd(const wchar_t *str, int fd)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (str[i] != 0)
	{
		sum += ft_putwchar_fd(str[i], fd);
		i++;
	}
	return (sum);
}
