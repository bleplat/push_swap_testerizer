/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autofree_begin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:22:40 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/04 20:45:45 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

/*
** Begin an autofree session.
** Return non-zero on failure.
*/

int		ft_autofree_begin(void)
{
	return ((ft_autofree_pushpop((void*)ft_autofree_pushpop) == NULL)
			? 0 : -1);
}
