/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ansicolor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 20:19:27 by bleplat           #+#    #+#             */
/*   Updated: 2020/01/15 14:45:36 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static int		putcolor(char *str, int color)
{
	char	*tmp;

	ft_strcat(str, "5;");
	if (!(tmp = ft_itoa(color % 256)))
		return (-1);
	ft_strcat(str, tmp);
	free(tmp);
	return (0);
}

static int		putrgb(char *str, int color)
{
	char	*tmp;

	ft_strcat(str, "2;");
	if (!(tmp = ft_itoa((color >> 16) % 256)))
		return (-1);
	ft_strcat(str, tmp);
	free(tmp);
	ft_strcat(str, ";");
	if (!(tmp = ft_itoa((color >> 8) % 256)))
		return (-1);
	ft_strcat(str, tmp);
	free(tmp);
	ft_strcat(str, ";");
	if (!(tmp = ft_itoa((color >> 0) % 256)))
		return (-1);
	ft_strcat(str, tmp);
	free(tmp);
	return (0);
}

/*
** Return a new string representing an escape sequence.
*/

char			*ft_ansicolor(int color, int flags)
{
	char		*new_str;

	color = ft_max(0, color);
	if (!(new_str = ft_strnew(32)))
		return (NULL);
	ft_strcat(new_str, "\e[");
	if (flags & FT_ANSICOLOR_FLAG_BACKGROUND)
		ft_strcat(new_str, "48;");
	else
		ft_strcat(new_str, "38;");
	if (flags & FT_ANSICOLOR_FLAG_RGB)
	{
		if (putrgb(new_str, color) < 0)
			return (ft_freen(new_str));
	}
	else
	{
		if (putcolor(new_str, color) < 0)
			return (ft_freen(new_str));
	}
	ft_strcat(new_str, "m");
	return (new_str);
}
