/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmo_should_malloc_succeed.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 22:33:31 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/14 02:41:29 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmo.h"

/*
** Tell if the malloc call number 'index' should succeed.
**
** In the logic, 2 is default and 3 is post-default.
** This function only return 0 or 1.
*/

int			ftmo_should_malloc_succeed(int index)
{
	int		mode;
	int		behave;

	mode = ftmo_getenv_mode();
	behave = 2;
	index -= ftmo_getenv_ignores();
	if (mode & FTMO_MODE_FAIL_ONCE)
	{
		if (index > 0)
			behave = 3;
		else if (index == 0)
			behave = (mode & FTMO_MODE_DEFAULT_FAIL) ? 1 : 0;
	}
	else if (behave == 3 && mode & FTMO_MODE_POSTDEFAULT_REPEAT_EACH)
		behave = ftmo_getenv_each(index, 1);
	else
		behave = ftmo_getenv_each(index, 0);
	if (behave == 0)
		return (0);
	if (behave == 2 && mode & FTMO_MODE_DEFAULT_FAIL)
		return (0);
	if (behave == 3 && mode & FTMO_MODE_POSTDEFAULT_FAIL)
		return (0);
	return (1);
}
