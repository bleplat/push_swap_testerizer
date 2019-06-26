/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirfilepath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 06:58:05 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/01 07:00:12 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Put a directory path and a file name together to make the full name
** of the file.
*/

char		*ft_dirfilepath(char *dir, char *file)
{
	char *dir_slash;

	if (!(dir_slash = ft_strjoin(dir, "/")))
		return (NULL);
	return (ft_strfuse(&dir_slash, &file, 1 | 4));
}
