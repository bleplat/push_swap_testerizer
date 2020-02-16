/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmo_getenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:09:05 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/14 03:53:22 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>

#include "libft.h"

#include "libftmo.h"

/*
** Retrieve env 'FTMO_EACH'[index] into *out.
** Return 0 for malloc should succeed.
** Return 1 for malloc should fail.
** Return 2 for default behavor.
** Return 3 for post default behavor.
**
** By defaut, return 2;
*/

int			ftmo_getenv_each(int index, int repeat)
{
	char	*env_str;
	int		len;

	if (index < 0)
		return (2);
	env_str = getenv("FTMO_EACH");
	if (env_str == NULL)
		return (2);
	len = 0;
	while (env_str[len])
		len++;
	if (repeat)
		index %= len;
	if (index >= len)
		return (3);
	return (env_str[index] - '0');
}

/*
** Retrieve env 'FTMO_IGNORES'
*/

int			ftmo_getenv_ignores(void)
{
	char	*env_str;
	int		ignores;

	env_str = getenv("FTMO_IGNORES");
	if (env_str == NULL)
		return (FTMO_COUNT_INFINITE);
	ignores = ft_atoi(env_str);
	if (ignores < 0)
		ignores = FTMO_COUNT_INFINITE;
	return (ignores);
}

/*
** Retrieve env 'FTMO_MODE'
*/

int			ftmo_getenv_mode(void)
{
	char	*env_str;

	env_str = getenv("FTMO_MODE");
	if (env_str == NULL)
		return (0);
	return (ft_atoi(env_str));
}

/*
** Get (or open) the file descriptor to log into
*/

int			ftmo_getenv_logd(int verbosity)
{
	static int	fd = -2;
	char		*env_str;

	if (fd == -2)
	{
		env_str = getenv("FTMO_LOGD");
		if (env_str == NULL)
			fd = -3;
		else if (env_str[0] == '0' && env_str[1] == '\0')
			fd = 0;
		else if (env_str[0] == '1' && env_str[1] == '\0')
			fd = 1;
		else if (env_str[0] == '2' && env_str[1] == '\0')
			fd = 2;
		else
			fd = open(env_str, O_WRONLY | O_CREAT);
	}
	if (fd == -3)
		return ((verbosity != 0) ? 2 : -1);
	return (fd);
}
