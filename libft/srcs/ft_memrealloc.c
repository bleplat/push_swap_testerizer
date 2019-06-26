/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:45:38 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/07 16:38:18 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memrealloc(void **mem, size_t *previous_size, size_t new_size)
{
	void		*new_mem;
	size_t		cp_len;

	if (*previous_size == new_size)
		return (0);
	if (mem == NULL)
		return (1);
	new_mem = ft_memalloc(new_size);
	if (new_mem == NULL)
		return (1);
	if (*mem != NULL)
	{
		cp_len = (*previous_size < new_size) ? (*previous_size) : new_size;
		ft_memcpy(new_mem, *mem, cp_len);
		ft_memdel(&(*mem));
	}
	*previous_size = new_size;
	*mem = new_mem;
	return (0);
}
