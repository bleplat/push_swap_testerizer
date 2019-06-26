/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleveralloc_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:47:41 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/04 20:55:39 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

/*
** Free everything queued for deletion since last call to ft_autofree_begin().
*/

void		ft_autofree_end(void)
{
	void		*to_free;

	while (1)
	{
		to_free = (void*)ft_autofree_pushpop(NULL);
		if (to_free == (void*)ft_autofree_pushpop || to_free == NULL)
			return ;
		free(to_free);
	}
}
