/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileusr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 06:43:48 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/01 08:10:34 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_files.h"

/*
** Get the owner id of a file.
*/

uid_t		ft_fileusr(const char *filename)
{
	struct stat		file_stats;

	if (lstat(filename, &file_stats) < 0)
		return (0);
	return (file_stats.st_uid);
}
