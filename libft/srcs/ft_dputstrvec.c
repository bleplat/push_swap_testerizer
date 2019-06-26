/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputstrvec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 04:28:59 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 19:13:29 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_dputstrvec(int fd, const char **vec, int count, const char *sep)
{
	int			i;

	i = 0;
	while (i < count || count < 0)
	{
		if (!vec[i])
			break ;
		if (i > 0 && sep != NULL)
			ft_putstr_fd(sep, fd);
		ft_putstr_fd(vec[i], fd);
		i++;
	}
	return (i);
}
