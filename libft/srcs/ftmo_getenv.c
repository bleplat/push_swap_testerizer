/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmo_getenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:09:05 by bleplat           #+#    #+#             */
/*   Updated: 2019/05/09 22:11:59 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>

#include "libftmo.h"

/*
** Retrieve env 'FTMO_EACH'[index] into *out.
** Return 1 if *out changed.
*/

int			ftmo_getenv_each(int *out, int index)
{
	char	*env_str;
	int		len;

	if (index < 0)
		return (0);
	env_str = getenv("FTMO_EACH");
	if (env_str == NULL)
		return (0);
	len = 0;
	while (env_str[len])
		len++;
	if (index >= len)
		return (0);
	(*out) = (env_str[index] == 0) ? 0 : 1;
	return (1);
}

/*
** Retrieve env 'FTMO_COUNT'
*/

int			ftmo_getenv_count(void)
{
	char	*env_str;

	env_str = getenv("FTMO_COUNT");
	if (env_str == NULL)
		return (FTMO_COUNT_INFINITE);
	return (atoi(env_str));
}

/*
** Retrieve env 'FTMO_MODE'
*/

int			ftmo_getenv_mode(void)
{
	char	*env_str;

	env_str = getenv("FTMO_MODE");
	if (env_str == NULL)
		return (FTMO_MODE_MALLOC);
	return (atoi(env_str));
}

/*
** Get (or open) the file descriptor to log into
*/

int			ftmo_getenv_logd(void)
{
	char	*env_str;

	env_str = getenv("FTMO_LOGD");
	if (env_str == NULL)
		return (-1);
	if (env_str[0] == '0' && env_str[1] == '\0')
		return (0);
	if (env_str[0] == '1' && env_str[1] == '\0')
		return (1);
	if (env_str[0] == '2' && env_str[1] == '\0')
		return (2);
	return (open(env_str, O_WRONLY | O_CREAT));
}
