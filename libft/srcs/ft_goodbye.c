/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goodbye.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:29:02 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/05 21:26:45 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Say Good bye :)
*/

int			ft_goodbye(void)
{
	int		foreground;
	int		background;

	foreground = (ft_urandom() + 256) % 256;
	background = (ft_urandom() + 256) % 256;
	ft_printf("%y%#yGood bye!{}\n", foreground, background);
	return (0);
}
