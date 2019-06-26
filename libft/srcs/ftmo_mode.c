/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_override.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:09:05 by bleplat           #+#    #+#             */
/*   Updated: 2019/05/09 20:28:54 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmo.h"

/*
** ftmo_mode:
**
** Define the behavior of malloc, according to 'mode' (or's them together):
** - FTMO_MODE_FAIL (1): default behavior is to fail (default is malloc).
** - FTMO_MODE_SWITCH (4): once the count reached, dont reset.
** - FTMO_MODE_EACH (8): use env variable 'FTMO' to decide when to succeed
** or fail.
** - FTMO_MODE_TRIGGER: get if malloc should succeed and trigger next.
*/

int			ftmo_mode(int new_mode)
{
	static int			mode = 0;
	int					count;
	int					choice;

	if (new_mode != FTMO_MODE_TRIGGER)
	{
		mode = new_mode;
		return (-1);
	}
	choice = 0;
	if (mode & FTMO_MODE_FAIL)
		choice = 1;
	count = ftmo_count(FTMO_COUNT_TRIGGER);
	if (count == 0)
		choice = 1 - choice;
	if (count < 0 && (mode & FTMO_MODE_SWITCH))
		choice = 1 - choice;
	if (count <= 0 && (mode & FTMO_MODE_EACH))
		ftmo_getenv_each(&choice, -count);
	return (choice);
}
