/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftmo_region.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 03:52:33 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/15 00:16:54 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTMO_REGION_H
# define LIBFTMO_REGION_H

/*
** Structure to store malloced regions.
*/

struct							s_ftmo_region
{
	long				index;
	size_t				size;
	void				*ptr;
	char				**calltree;
};
typedef struct s_ftmo_region	t_ftmo_region;

t_ftmo_region					ftmo_make_reg(int index, void *ptr, size_t sz);

#endif
