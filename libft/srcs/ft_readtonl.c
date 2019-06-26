/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readtonl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:54:33 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/04 23:26:13 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

static void		zeroize(int *i_new, char **newstr,
						size_t *newsize, int *read_rst)
{
	(*newstr) = ft_memalloc(8);
	(*newsize) = (*newstr) ? 8 : 0;
	(*i_new) = (*newstr) ? 0 : -1;
	(*read_rst) = (*newstr) ? 0 : -3;
}

/*
** Read a fd char by char and put in 'p_dst' everything read, ended by
** a '\0', until a '\n' is encountered, this '\n' included.
** Return a negative code on error.
** Return -2 if max_line_size was reached.
** Return -3 on malloc failure.
** Return the count of characters read otherwise.
** /!\ You must free the outputed line yourself.
*/

int				ft_readtonl(int fd, char **p_dst, int max_line_size)
{
	char		read_c;
	int			read_rst;
	char		*nstr;
	size_t		newsize;
	int			i_new;

	zeroize(&i_new, &nstr, &newsize, &read_rst);
	while (nstr && (read_rst = read(fd, &read_c, 1)) > 0)
	{
		if (max_line_size >= 0 && i_new >= max_line_size)
			return (-2 + ft_free0(nstr));
		if ((size_t)(i_new + 1) >= newsize)
			if (ft_memrealloc((void**)&nstr, &newsize, ft_min(8, newsize * 2)))
				return (-3 + ft_free0(nstr));
		nstr[i_new] = read_c;
		nstr[i_new + 1] = '\0';
		if (read_c == '\n' && (i_new += 1))
			break ;
		i_new++;
	}
	if (read_rst < 0)
		return (read_rst + ft_free0(nstr));
	if (p_dst != NULL)
		*p_dst = nstr;
	return (i_new);
}
