/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_override.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:09:05 by bleplat           #+#    #+#             */
/*   Updated: 2019/05/09 20:29:25 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmo.h"

/*
** ftmo_count:
**
** Set a count or decrease the current by one.
** This is used by malloc logic, like "how many success/failure are requiered".
** It returns its last count, updating it, or decreasing it by 1.
** Possible values:
** FTMO_COUNT_INFINITE: count will be set to high and not decrease.
** <positive_integer>: countset to 'new_count', and decrease by one every call
** FTMO_COUNT_TRIGGER: trigger the next count and return the current one.
** FTMO_COUNT_GET: get what should be the next count without triggering.
*/

int			ftmo_count(int new_count)
{
	static int		count = FTMO_COUNT_INFINITE;
	int				rst;

	rst = count;
	if (rst != FTMO_COUNT_INFINITE && new_count != FTMO_COUNT_GET)
		count -= 1;
	if (new_count != FTMO_COUNT_TRIGGER && new_count != FTMO_COUNT_GET)
		count = new_count;
	return (rst);
}
