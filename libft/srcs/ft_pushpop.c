/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:16:04 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/03 15:02:11 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

/*
** If to_push is NULL, then give the last pointer recorded by the function.
** If to_push is not NULL, then record it, ruturning NULL on success, or
** to_push on failure.
*/

const void		*ft_pushpop(const void *to_push)
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
