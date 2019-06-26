/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:17:15 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/13 20:01:29 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*first_new;
	t_list			*last_new;

	first_new = NULL;
	while (lst != NULL)
	{
		if (first_new == NULL)
		{
			first_new = f(lst);
			last_new = first_new;
		}
		else
		{
			last_new->next = f(lst);
			last_new = last_new->next;
		}
		if (last_new == NULL)
		{
			ft_lstdel(&first_new, NULL);
			return (NULL);
		}
		lst = lst->next;
	}
	return (first_new);
}
