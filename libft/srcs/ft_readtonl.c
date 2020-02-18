/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readtonl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:54:33 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/17 20:51:59 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

/*
** Read a fd char by char and put in 'p_dst' everything read, ended by
** a '\0', until a '\n' is encountered, this '\n' included.
** p_dst will be set to NULL on error or if 0 chars were read.
** Return a negative code on error.
** Return -2 if max_line_size was reached.
** Return -3 on malloc failure.
** Return the count of characters read otherwise.
** /!\ You must free the outputed line yourself.
**
** Might be used in conjunction with ft_strpopnls().
*/

int				ft_readtonl(int fd, char **p_dst, int max_line_size)
{
	t_array			*chars_a;
	char			*p_char;
	char			c;
	char			c_count;

	*p_dst = NULL;
	if (!(chars_a = ft_array_new(sizeof(char), ft_min(max_line_size + 1, 8))))
		return (FT_READTONL_MALLOC_FAILED);
	while ((c_count = read(fd, &c, 1)) > 0)
	{
		if (chars_a->item_count > max_line_size)
			return (ft_array_del0(&chars_a) + FT_READTONL_LINE_TOO_LONG);
		if (!(p_char = ft_array_newitem(chars_a)))
			return (ft_array_del0(&chars_a) + FT_READTONL_MALLOC_FAILED);
		*p_char = c;
		if (c == '\n')
			break ;
	}
	if (chars_a->item_count == 0)
		return (ft_array_del0(&chars_a));
	if (!(p_char = ft_array_newitem(chars_a)))
		return (ft_array_del0(&chars_a) + FT_READTONL_MALLOC_FAILED);
	*p_char = '\0';
	*p_dst = chars_a->items;
	return ((chars_a->item_count - 1) + ft_free0(chars_a));
}
