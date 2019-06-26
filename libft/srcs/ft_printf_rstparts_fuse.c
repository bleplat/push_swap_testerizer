/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_rstparts_fuse.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:46:14 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/28 16:31:32 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ft_printf_helpers.h"

static char	*alloc_requ(t_array *parts_a)
{
	int		i_part;
	int		total_len;

	total_len = 0;
	i_part = 0;
	while (i_part < parts_a->item_count)
	{
		if (((t_printf_rstpart*)ft_array_at(parts_a, i_part))->str)
			total_len += ft_strlen(((t_printf_rstpart*)
						ft_array_at(parts_a, i_part))->str);
		i_part++;
	}
	return (ft_strnew(total_len));
}

static void	add_to_str(char *dst, int *i_dst, t_printf_rstpart *part)
{
	int		i_chr;

	if (!part->str)
		return ;
	i_chr = 0;
	while (part->str[i_chr] != '\0')
	{
		if (part->at_null && part->str[i_chr] == '@')
			dst[*i_dst] = '\0';
		else
			dst[*i_dst] = part->str[i_chr];
		i_chr++;
		(*i_dst) += 1;
	}
}

/*
** ft_printf_fuseparts()
**
** Create one big string from an array of t_printf_part
*/

char		*ft_printf_rstparts_fuse(t_array *parts_a)
{
	int		i_part;
	char	*cat_rst;
	int		i_rst;

	if (!(cat_rst = alloc_requ(parts_a)))
		return (NULL);
	i_part = 0;
	i_rst = 0;
	while (i_part < parts_a->item_count)
	{
		add_to_str(cat_rst, &i_rst,
			(t_printf_rstpart*)ft_array_at(parts_a, i_part));
		i_part++;
	}
	return (cat_rst);
}
