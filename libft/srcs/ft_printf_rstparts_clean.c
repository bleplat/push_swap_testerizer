/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_rstparts_clean.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:38:10 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/27 20:15:16 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_helpers.h"

int			ft_printf_rstparts_clean(t_array **parts_a)
{
	t_printf_rstpart	*parts;
	int					i_part;

	if (!parts_a || !(*parts_a))
		return (0);
	parts = (*parts_a)->items;
	i_part = 0;
	while (i_part < (*parts_a)->item_count)
	{
		free(parts[i_part].str);
		free(parts[i_part].fmt);
		i_part++;
	}
	free((*parts_a)->items);
	ft_memdel((void**)parts_a);
	return (0);
}
