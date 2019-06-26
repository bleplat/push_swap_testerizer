/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_files.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 04:17:22 by bleplat           #+#    #+#             */
/*   Updated: 2019/05/08 12:06:30 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FILES_H
# define LIBFT_FILES_H

# include <sys/stat.h>

# include "libft_types.h"

/*
** H e l p e r s
*/

char			*ft_dirfilepath(char *dir, char *file);
int				ft_strpopslashes(char *path);

char			*ft_strmode(mode_t mode);

char			*ft_usrname(uid_t uid);
char			*ft_grpname(gid_t gid);

/*
** F i l e s
*/

int				ft_listxattr(char **out, const char *path, int options);

mode_t			ft_filemode(const char *filename);
uid_t			ft_fileusr(const char *filename);
gid_t			ft_filegrp(const char *filename);
char			*ft_linkfolow(const char *link);

/*
** D i r e c t o r i e s
*/

int				ft_listdir(char ***out, const char *dir);

/*
** C o l o r i n g
*/

t_lscolors		ft_lscolors(void);
void			ft_filecforefont(char *dst, t_lscolors colors, t_stat stat);
void			ft_filecbackfont(char *dst, t_lscolors colors, t_stat stat);

#endif
