/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmo_choice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:09:35 by bleplat           #+#    #+#             */
/*   Updated: 2019/05/09 23:06:43 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmo.h"

static void		ftmo_init(void)
{
	ftmo_count(ftmo_getenv_mode());
	ftmo_count(ftmo_getenv_count());
	ftmo_log(FTMO_FUNC_SETUP, ftmo_getenv_logd(), (void*)0);
}

int				ftmo_choice(void)
{
	static int		need_init = 1;

	if (need_init)
	{
		ftmo_init();
		need_init = 0;
	}
	return (ftmo_mode(FTMO_MODE_TRIGGER));
}
