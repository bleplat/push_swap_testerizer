/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmo_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 22:36:12 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/15 00:21:07 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmo.h"

static void		move_regions(t_ftmo_region *dst, t_ftmo_region *src, long cnt)
{
	int		i_reg;

	i_reg = 0;
	while (i_reg < cnt)
	{
		dst[i_reg] = src[i_reg];
		i_reg++;
	}
}

static int		expend_regions(t_ftmo_region **regions, long *capacity)
{
	long			new_cap;
	t_ftmo_region	*new_regions;

	if ((*regions) == NULL)
		(*capacity) = 0;
	new_cap = ((*capacity) > 0) ? ((*capacity) * 2) : 8;
	if (!(new_regions = ftmo_libc_malloc(sizeof(t_ftmo_region) * new_cap)))
		return (-1);
	move_regions(new_regions, *regions, *capacity);
	ftmo_libc_free(*regions);
	*capacity = new_cap;
	*regions = new_regions;
	return (0);
}

static int		dofree(t_ftmo_region *regs, long *count, void *ptr)
{
	int		i_reg;

	i_reg = 0;
	while (i_reg < (*count))
	{
		if (regs[i_reg].ptr == ptr)
		{
			move_regions(&regs[i_reg], &regs[i_reg + 1], (*count) - i_reg - 1);
			(*count)--;
			return (0);
		}
		i_reg++;
	}
	ftmo_log_p(-1, "Freed pointer was not malloced: ", ptr, "!");
	return (-1);
}

static void		verify(t_ftmo_region *regions, int count)
{
	int		i;

	if (count != 0)
	{
		i = 0;
		while (i < count)
		{
			ftmo_log_r(-1, "LEAK ", &regions[i], "");
			ftmo_libc_free(regions[i].calltree);
			i++;
		}
		ftmo_log(1, "Note LIBFTMO catching leaks may blind other tools!");
	}
}

/*
** Keep track of allocations.
**
** Possible actions:
** - FTMO_TRACK_ACTION_MALLOC
** - FTMO_TRACK_ACTION_FREE
** - FTMO_TRACK_ACTION_VERIFY
** - FTMO_TRACK_ACTION_CLEANUP
**
** TODO: incorrect cleanup/verify done in a hurry. To be fixed.
*/

int				ftmo_track(int track_action, void *ptr, size_t sz, int mindex)
{
	static t_ftmo_region		*regions = NULL;
	static long					region_count = 0;
	static long					region_capacity = 0;

	if (track_action == FTMO_TRACK_MALLOC && ptr != NULL)
	{
		if (regions == NULL || region_count == region_capacity)
			if (expend_regions(&regions, &region_capacity) < 0)
				return (ftmo_log(-1, "Internal allocation failed!"));
		region_count++;
		regions[region_count - 1] = ftmo_make_reg(mindex, ptr, sz);
	}
	if (track_action == FTMO_TRACK_FREE && ptr != NULL)
		return (dofree(regions, &region_count, ptr));
	if (track_action == FTMO_TRACK_VERIFY)
		verify(regions, region_count);
	if (track_action == FTMO_TRACK_CLEANUP)
	{
		ftmo_libc_free(regions);
		regions = NULL;
	}
	return (0);
}
