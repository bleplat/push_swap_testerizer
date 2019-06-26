/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filemode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 06:43:48 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/01 06:50:48 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_files.h"

/*
** Get the mode of a file.
*/

mode_t		ft_filemode(const char *filename)
{
	struct stat		file_stats;

	if (lstat(filename, &file_stats) < 0)
		return (0);
	return (file_stats.st_mode);
}
