/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 01:47:13 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/01 02:29:18 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** Free a zero delimited vector with several layers.
** Deep of 0 mean 'Only free this pointer'
** Deep of 1 mean 'free this pointer and sub-pointers of this vector'
** And so on.
*/

void		ft_vecdel(void **vec, int deep)
{
	void	**subvec;
	int		i;

	if (deep > 0)
	{
		subvec = (void**)(*vec);
		i = 0;
		while (subvec[i] != NULL)
		{
			ft_vecdel(&subvec[i], deep - 1);
			i++;
		}
	}
	free(*vec);
	*vec = NULL;
}
