/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdir_demo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:06:00 by bleplat           #+#    #+#             */
/*   Updated: 2019/05/16 20:06:02 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

void		advanced(char *dir, char **dir_names)
{
	char			*fullpath;
	const char		*smode;
	char			*usr;
	char			*grp;

	while (*dir_names != NULL)
	{
		if (!(fullpath = ft_dirfilepath(dir, *dir_names)))
			perror(*dir_names);
		else
		{
			smode = ft_strmode(ft_filemode(fullpath));
			usr = ft_usrname(ft_fileusr(fullpath));
			grp = ft_grpname(ft_filegrp(fullpath));
			ft_printf("%s  %s  %s  %s\n", smode, usr, grp, *dir_names);
			free((void*)fullpath);
			free((void*)smode);
			free((void*)usr);
			free((void*)grp);
		}
		dir_names++;
	}
}

int			listdir(char *dir, int shouldlist)
{
	char		**dir_names;

	if (ft_listdir(&dir_names, dir) < 0)
	{
		perror(dir);
		return (errno);
	}
	if (shouldlist)
		advanced(dir, dir_names);
	else
	{
		ft_putstrvec((const char**)dir_names, -1, "\n");
		ft_putchar('\n');
	}
	ft_vecdel((void**)&dir_names, 1);
	return (0);
}

int			main(int argc, char **argv)
{
	char		*dir;
	int			shouldlist;

	shouldlist = 0;
	dir = ".";
	if (argc > 1)
	{
		dir = argv[1];
		if (ft_strcmp(argv[1], "-l") == 0)
		{
			shouldlist = 1;
			dir = ".";
			if (argc > 2)
				dir = argv[2];
		}
	}
	return (listdir(dir, shouldlist));
}
