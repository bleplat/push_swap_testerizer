/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:21:22 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/14 17:57:28 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static void			free_str(void *p, size_t ignore)
{
	(void)ignore;
	free(p);
}

static int			add_str(t_list **list, const char *str, size_t len)
{
	t_list		*new_elem;

	new_elem = (t_list*)malloc(sizeof(t_list) * 1);
	if (*list == NULL)
		*list = new_elem;
	else
		ft_lstlast(*list)->next = new_elem;
	if (new_elem == NULL)
	{
		ft_lstdel(list, &free_str);
		return (-1);
	}
	new_elem->next = NULL;
	new_elem->content_size = len + 1;
	new_elem->content = ft_strsub(str, 0, len);
	if (new_elem->content == NULL)
	{
		ft_lstdel(list, &free_str);
		return (-1);
	}
	return (0);
}

t_list				*ft_strlstsplit(char const *str, char c)
{
	t_list		*new_list;
	int			i_str;
	int			w_len;

	new_list = NULL;
	i_str = 0;
	while (str[i_str] != '\0')
	{
		if (str[i_str] == c)
			i_str++;
		else
		{
			w_len = 0;
			while (str[i_str + w_len] != '\0' && str[i_str + w_len] != c)
				w_len++;
			if (add_str(&new_list, &str[i_str], w_len) < 0)
				return (NULL);
			i_str += w_len;
		}
	}
	return (new_list);
}
