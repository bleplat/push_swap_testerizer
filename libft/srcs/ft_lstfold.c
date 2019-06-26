/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:52:45 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/14 18:48:12 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void			*ft_lstfold(t_list *lst, void *(*f)(void *e1, void *e2))
{
	void	*next;
	void	*sum;

	if (lst == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (ft_memdup(lst->content, lst->content_size));
	else
	{
		next = ft_lstfold(lst->next, f);
		if (next == NULL)
			return (NULL);
		sum = f(lst->content, next);
		free(next);
		return (sum);
	}
}
