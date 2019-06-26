/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:24:25 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/03 15:00:22 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Uninsert an item from a list.
** This do not free the item.
** Return NULL if the item was not in the list.
*/

t_list		*ft_lstpop(t_list **list, t_list *item)
{
	t_list		*search;

	if (*list == NULL)
		return (NULL);
	if (*list == item)
		*list = item->next;
	else
	{
		search = *list;
		while (search->next != NULL)
		{
			if (search->next == item)
			{
				search->next = item->next->next;
				item->next = NULL;
				return (item);
			}
			search = search->next;
		}
		return (NULL);
	}
	return (item);
}
