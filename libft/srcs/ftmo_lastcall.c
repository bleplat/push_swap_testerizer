/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmo_lastcall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 22:11:24 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/14 02:33:01 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmo.h"

void		ftmo_lastcall(void)
{
	ftmo_track(FTMO_TRACK_VERIFY, NULL, 0, -1);
	ftmo_track(FTMO_TRACK_CLEANUP, NULL, 0, -1);
}
