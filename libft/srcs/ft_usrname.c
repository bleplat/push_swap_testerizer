/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usrname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 08:00:33 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 19:23:30 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <pwd.h>

#include "libft.h"

char			*ft_usrname(uid_t uid)
{
	struct passwd	*p;
	char			*cp_name;

	errno = 0;
	if (!(p = getpwuid(uid)))
		return (NULL);
	if (!(cp_name = ft_strdup(p->pw_name)))
		errno = ENOMEM;
	return (cp_name);
}
