/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 05:40:14 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/01 06:49:57 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>

#include "libft.h"

static void		fill_entry_type(mode_t mode, char *str)
{
	if (mode & S_IFIFO)
		str[0] = 'p';
	else if (mode & S_IFCHR)
		str[0] = 'c';
	else if (mode & S_IFDIR)
		str[0] = 'd';
	else if (mode & S_IFBLK)
		str[0] = 'b';
	else if (mode & S_IFREG)
		str[0] = '-';
	else if (mode & S_IFLNK)
		str[0] = 'l';
	else if (mode & S_IFSOCK)
		str[0] = 's';
	else if (mode & S_IFWHT)
		str[0] = 'w';
	else
		str[0] = '?';
}

static void		fill_basic(mode_t mode, char *str)
{
	str[1] = (mode & S_IRUSR) ? 'r' : '-';
	str[2] = (mode & S_IWUSR) ? 'w' : '-';
	str[3] = (mode & S_IXUSR) ? 'x' : '-';
	if (mode & S_ISUID)
		str[3] = (mode & S_IXUSR) ? 's' : 'S';
	str[4] = (mode & S_IRGRP) ? 'r' : '-';
	str[5] = (mode & S_IWGRP) ? 'w' : '-';
	str[6] = (mode & S_IXGRP) ? 'x' : '-';
	if (mode & S_ISGID)
		str[6] = (mode & S_IXGRP) ? 's' : 'S';
	str[7] = (mode & S_IROTH) ? 'r' : '-';
	str[8] = (mode & S_IWOTH) ? 'w' : '-';
	str[9] = (mode & S_IXOTH) ? 'x' : '-';
	if (mode & S_ISVTX)
		str[9] = (mode & S_IXOTH) ? 't' : 'T';
}

/*
** Return a string representation of a file mode in 11 usable chars (+ a '\0').
** So, indeed, there is 1 extra char to hold the extended attributes char.
*/

char			*ft_strmode(mode_t mode)
{
	char	*str;

	if (mode == 0)
		return (NULL);
	if (!(str = ft_strnew(11)))
		return (NULL);
	fill_entry_type(mode, str);
	fill_basic(mode, str);
	return (str);
}
