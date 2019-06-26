/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper_inplace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:24:11 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/12 12:00:25 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Make all charsun a string uppercase.
*/

void			ft_strtoupper_inplace(char *str)
{
	if (str != NULL)
	{
		while (*str != '\0')
		{
			*str = ft_toupper(*str);
			str++;
		}
	}
}
