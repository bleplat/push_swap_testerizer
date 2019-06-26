/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pause.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:43:07 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/04 20:52:30 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

/*
** Pause and ask the user to press Enter.
** Return 1 if they did.
** return 0 if end of input was reached.
** Return -1 on error.
*/

int						ft_pause(void)
{
	char		c;
	int			rst;

	ft_printf("Press enter to continue...");
	while ((rst = read(0, &c, 1)) > 0)
	{
		if (c == '\n')
			return (1);
	}
	return (rst);
	return (read(0, NULL, 0));
}
