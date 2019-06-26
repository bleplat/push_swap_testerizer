/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:53:44 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/04 14:48:49 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "libft_readline.h"

/*
** Return an item from the instances list corresponding to a file descriptor.
** If uninsert is not 0 then the item is also removed from the list (but not
** freed)
*/

static t_ftrl	*find_rlitem(t_ftrl **rllist, const int fd, int uninsert)
{
	t_ftrl		*prev;
	t_ftrl		*curr;

	prev = NULL;
	curr = *rllist;
	while (curr != NULL)
	{
		if (curr->fd == fd)
		{
			if (uninsert)
			{
				if (prev == NULL)
					*rllist = curr->next;
				else
					prev->next = curr->next;
			}
			return (curr);
		}
		prev = curr;
		curr = curr->next;
	}
	return (NULL);
}

/*
** Save extra read from buffer to static list.
** No save is performed if no data to save.
*/

static int		set_extra(t_ftrl **rllist, const int fd, char *extra, size_t s)
{
	t_ftrl		*rlitem;
	t_ftrl		*lastrl;

	if (s == 0)
		return (0);
	if (!(rlitem = ft_memalloc(sizeof(*rlitem))))
		return (-1);
	if (!(rlitem->content = malloc(s)))
		return (-1 + ft_free0(rlitem));
	rlitem->fd = fd;
	rlitem->size = s;
	ft_memcpy(rlitem->content, extra, s);
	lastrl = *rllist;
	while (lastrl && lastrl->next)
		lastrl = lastrl->next;
	if (lastrl)
		lastrl->next = rlitem;
	else
		*rllist = rlitem;
	return (0);
}

/*
** Fill the buffers read() would fill and return, with the data
** from the previous call, so you can just use those like if read() have
** been called.
** Also clear the buffer.
*/

static int		pop_remains(t_ftrl **rllist, const int fd, char *b, int *amnt)
{
	t_ftrl		*rlitem;

	rlitem = find_rlitem(rllist, fd, 1);
	ft_bzero(b, FT_READLINE_BUFF_SIZE);
	if (rlitem == NULL)
	{
		*amnt = 0;
	}
	else
	{
		*amnt = rlitem->size;
		ft_memcpy(b, rlitem->content, rlitem->size);
		free(rlitem->content);
		free(rlitem);
	}
	return (*amnt);
}

/*
** Append srclen characters from src to the end of *dst,
** realocating it so it's big enought to hold the result.
** free dst on error ans set it to NULL.
*/

static int		maybe_append(char **dst, int dstlen, char *src, int srclen)
{
	char		*prev_dst;

	if (*dst == NULL)
		if (!(*dst = ft_strdup("")))
			return (-1);
	if (srclen == 0)
		return (dstlen);
	prev_dst = *dst;
	(*dst) = (char*)malloc(dstlen + srclen + 1);
	if (*dst == NULL)
		return (-1 + ft_free0(prev_dst));
	(*dst)[0] = '\0';
	ft_memcpy(*dst, prev_dst, dstlen);
	ft_memcpy(*dst + dstlen, src, srclen);
	(*dst)[dstlen + srclen] = '\0';
	free(prev_dst);
	return (dstlen + srclen);
}

/*
** ft_readline()
** Read a file descriptor line by line.
** Also retrieve the final '\n' if the line contains one.
** Return -1 on error.
** Return 0 if nothing is available for reading.
** Return the count of characters read otherwise..
**
** This version keep track of different fd, so you can call it with
** several ones in any order.
**
** To free memory used by this function, call it for the file descriptor
** you were using with dst == NULL.
** You do not need this step if you read files to their end.
*/

int				ft_readline(const int fd, char **line)
{
	static t_ftrl		*rllist = NULL;
	t_ftrl_container	c;

	c.line_len = 0;
	c.tn = pop_remains(&rllist, fd, c.b, &c.a) ? -42 : 0;
	if (line == NULL)
		return (-1);
	*line = NULL;
	while (c.tn < 0 || (c.a = read(fd, c.b, FT_READLINE_BUFF_SIZE)) > 0)
	{
		c.tn = 0;
		while (c.tn < c.a && c.b[c.tn] != '\n')
			c.tn++;
		if ((c.line_len = maybe_append(line, c.line_len, c.b, c.tn
						+ ((c.b[c.tn] == '\n' && c.tn < c.a) * 1))) < 0)
			return (-1);
		if (c.tn < c.a - 1)
			if (set_extra(&rllist, fd, &c.b[c.tn + 1], c.a - c.tn - 1))
				return (-1 + ft_memdel0((void**)line));
		if (c.tn < c.a)
			return (c.line_len);
	}
	if (c.a < 0)
		return (-1);
	return ((*line == NULL) ? 0 : c.line_len);
}
