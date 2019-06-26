/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lscolors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 22:22:44 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 18:42:05 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_lscolors			ft_lscolors(void)
{
	t_lscolors		lscolors;

	lscolors = getenv("LSCOLORS");
	if (lscolors == NULL || ft_strlen(lscolors) != 22)
		return ("Gxfxcxdxbxegedabagacad");
	return (lscolors);
}
