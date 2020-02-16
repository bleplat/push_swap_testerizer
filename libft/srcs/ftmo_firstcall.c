/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmo_firstcall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:59:56 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/14 02:32:07 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libftmo.h"

/*
** Function called once in ftmo.
** It is called just before the first call to malloc, by the override.
** Its purpose is to contain the initialization stuff, including the setup of
** the exit function, ftmo_lastcall.
*/

int				ftmo_firstcall(void)
{
	int			rst;

	rst = atexit(ftmo_lastcall);
	return (rst);
}
