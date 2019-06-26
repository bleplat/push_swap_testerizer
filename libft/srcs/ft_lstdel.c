/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:08:46 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/13 19:52:51 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*to_del;
	t_list		*next_to_del;

	to_del = *alst;
	while (to_del != NULL)
	{
		next_to_del = to_del->next;
		if (del != NULL)
			del(to_del->content, to_del->content_size);
		free(to_del);
		to_del = next_to_del;
	}
	*alst = NULL;
}
