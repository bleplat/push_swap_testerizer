/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:15:16 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/14 19:18:27 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_lstcount(t_list *list)
{
	int		count;

	if (list == NULL)
		return (0);
	count = 1;
	while (list->next != NULL)
	{
		list = list->next;
		count++;
	}
	return (count);
}
