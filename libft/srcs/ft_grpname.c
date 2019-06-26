/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grpname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 07:49:18 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 19:25:53 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <grp.h>

#include "libft.h"

char		*ft_grpname(gid_t gid)
{
	struct group	*g;
	char			*cp_name;

	errno = 0;
	if (!(g = getgrgid(gid)))
		return (NULL);
	if (!(cp_name = ft_strdup(g->gr_name)))
		errno = ENOMEM;
	return (cp_name);
}
