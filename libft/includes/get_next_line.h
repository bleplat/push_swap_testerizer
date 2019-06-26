/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:49:29 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/16 21:59:48 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8

typedef struct		s_gnli
{
	int			fd;
	char		*extra;
	size_t		size;
}					t_gnli;

int					get_next_line(const int fd, char **line);

#endif
