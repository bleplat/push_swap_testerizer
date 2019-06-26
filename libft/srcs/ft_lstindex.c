/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:19:09 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/14 19:34:54 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstindex(t_list *list, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		list = list->next;
		i++;
		if (list == NULL)
			return (NULL);
	}
	return (list);
}
