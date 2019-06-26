/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autofree_pushpop.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:18:25 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/04 20:44:49 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

/*
** Function used by other autofree functions,
** you should use ft_autofree() instead.
** Queue a pointer for later deletion.
** Return NULL on success.
** Return the pointer on error.
*/

const void		*ft_autofree_pushpop(const void *to_push)
{
	static t_list		*recorded = NULL;
	t_list				*new_record;
	void				*to_return;

	if (to_push == NULL)
	{
		new_record = ft_lstpop(&recorded, recorded);
		if (!new_record)
			return (NULL);
		to_return = new_record->content;
		free(new_record);
		return (to_return);
	}
	new_record = ft_lstnew(NULL, 0);
	if (!new_record)
		return (to_push);
	new_record->content = (void*)to_push;
	new_record->next = recorded;
	recorded = new_record;
	return (NULL);
}
