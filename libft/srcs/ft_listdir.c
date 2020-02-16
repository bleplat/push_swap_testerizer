/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:08:03 by bleplat           #+#    #+#             */
/*   Updated: 2019/05/16 20:08:05 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <errno.h>

#include "libft.h"

static char		*ft_direntryname(struct dirent *entry)
{
	char		*rst;
	static char	*dirsep = "/";

	if (!(rst = ft_strsub(entry->d_name, 0, entry->d_namlen)))
		return (NULL);
	if (entry->d_type == DT_DIR)
		return (ft_strfuse(&rst, &dirsep, 1 | FT_FREETASK_ALWAY));
	else
		return (rst);
}

static int		ft_listdir_p3(t_array *strarray, DIR *dir_p)
{
	char			**newitem;
	struct dirent	*entry;

	while ((entry = readdir(dir_p)) != NULL)
	{
		if (!(newitem = ft_array_newitem(strarray)))
		{
			errno = ENOMEM;
			return (-1);
		}
		if (!(*newitem = ft_direntryname(entry)))
		{
			errno = ENOMEM;
			return (-1);
		}
	}
	if (!(newitem = ft_array_newitem(strarray)))
	{
		errno = ENOMEM;
		return (-1);
	}
	*newitem = NULL;
	return (0);
}

static int		ft_listdir_p2(char ***out, DIR *dir_p)
{
	t_array			*strarray;

	if (!(strarray = ft_array_new(sizeof(char*), 4)))
	{
		errno = ENOMEM;
		return (-1);
	}
	if (ft_listdir_p3(strarray, dir_p) < 0)
	{
		ft_array_del(&strarray);
		return (-1);
	}
	*out = strarray->items;
	return (strarray->item_count + ft_free0(strarray));
}

/*
** Output to 'out' a NULL terminated vector containing the files and
** directories inside the specified directory.
** Outputed directories ends with '/'.
*/

int				ft_listdir(char ***out, const char *dir)
{
	int				result;
	DIR				*dir_p;

	if ((dir_p = opendir(dir)) == NULL)
		return (-1);
	result = ft_listdir_p2(out, dir_p);
	if (closedir(dir_p))
		return (-1);
	return (result);
}
