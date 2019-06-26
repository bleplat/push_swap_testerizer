/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filecolor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:59:48 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 19:16:56 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			bake(char *dst, char cchar, int isback)
{
	static char *formats[12] = { "Jan", "Feb", "Mar",
								"Apr", "May", "Jun",
								"Jul", "Aug", "Sep",
								"Oct", "Nov", "Dec"};

	(void)formats;
	(void)dst;
	(void)cchar;
	(void)isback;
	return (0);
}

static void			getchars(char *cchars, t_lscolors colors, t_stat stat)
{
	(void)cchars;
	(void)colors;
	(void)stat;
}

void				ft_filecolor(char *dst, t_lscolors colors, t_stat stat)
{
	char		cchars[2];
	int			i_chr;

	dst[0] = '\0';
	if (colors == NULL)
		return ;
	i_chr = 0;
	getchars(cchars, colors, stat);
	i_chr += bake(dst, cchars[0], 0);
	i_chr += bake(dst, cchars[0], 1);
}
