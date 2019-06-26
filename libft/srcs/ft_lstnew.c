/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:54:09 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/15 16:19:21 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new_elem;

	new_elem = malloc(sizeof(t_list) * 1);
	if (new_elem == NULL)
		return (NULL);
	if (content != NULL)
	{
		new_elem->content_size = content_size;
		new_elem->content = malloc(content_size);
		if (new_elem->content == NULL)
		{
			free(new_elem);
			return (NULL);
		}
		ft_memcpy(new_elem->content, content, content_size);
	}
	else if (content == NULL)
	{
		new_elem->content = NULL;
		new_elem->content_size = 0;
	}
	new_elem->next = NULL;
	return (new_elem);
}
