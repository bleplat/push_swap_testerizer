/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_readline.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:34:49 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/04 14:46:43 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_READLINE_H
# define LIBFT_READLINE_H

# define FT_READLINE_BUFF_SIZE 4

/*
** t_ftrl_container
**
** Container used in ft_readline()
** see srcs/ft_readline.c for details.
**
** b: buffer.
** a: amount read in buffer.
** tn: amount of chars To the New line.
** line_len: size of the the line beeing returned.
*/

typedef struct s_ftrl_container	t_ftrl_container;
struct							s_ftrl_container
{
	char		b[FT_READLINE_BUFF_SIZE];
	int			a;
	int			tn;
	int			line_len;
};

/*
** t_ftrl
**
** Chained list used in ft_readline().
*/

typedef struct s_ftrl			t_ftrl;
struct							s_ftrl
{
	int			fd;
	char		*content;
	size_t		size;
	t_ftrl		*next;
};

int								ft_readline(const int fd, char **line);

#endif
