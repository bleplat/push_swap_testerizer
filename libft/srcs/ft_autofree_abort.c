/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autofree_abort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:12:45 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/07 16:12:47 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

/*
** Forget everything queued for deletion since last call to
** ft_autofree_begin().
*/

void		ft_autofree_abort(void)
{
	void		*to_free;

	while (1)
	{
		to_free = (void*)ft_autofree_pushpop(NULL);
		if (to_free == (void*)ft_autofree_pushpop || to_free == NULL)
			return ;
	}
}
