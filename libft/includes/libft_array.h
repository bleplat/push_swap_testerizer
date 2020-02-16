/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_array.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:53:32 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/16 14:12:56 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ARRAY_H
# define LIBFT_ARRAY_H

/*
** A r r a y
**
** A "c++ vector" like structure and functions.
*/

typedef struct s_array		t_array;
struct						s_array
{
	void		*items;
	int			item_size;
	int			item_count;
	int			item_capacity;
};

t_array						*ft_array_new(int item_size, int item_capacity);
void						ft_array_del(t_array **a);
int							ft_array_del0(t_array **a);
int							ft_array_reserve(t_array *a, int item_capacity);
void						*ft_array_newitem(t_array *a);
int							ft_array_shrink(t_array *a);
void						*ft_array_at(t_array *a, int index);
void						ft_array_clear(t_array *a);
int							ft_array_reset(t_array *a, int item_count);
void						ft_array_removeat(t_array *a, int index);

#endif
