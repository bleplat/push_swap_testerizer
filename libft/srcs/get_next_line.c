/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:53:44 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/18 18:47:53 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

#include "get_next_line.h"

/*
** Return an item from the instances list corresponding to a file descriptor.
** If uninsert is not 0 then the item is also removed from the list (but not
** freed)
*/

static t_list	*find_iitem(t_list **ilist, const int fd, int uninsert)
{
	t_list		*prev;
	t_list		*curr;

	prev = NULL;
	curr = *ilist;
	while (curr != NULL)
	{
		if (((t_gnli*)(curr->content))->fd == fd)
		{
			if (uninsert)
			{
				if (prev == NULL)
					*ilist = curr->next;
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

static int		set_extra(t_list **ilist, const int fd, char *extra, size_t s)
{
	t_list		*iitem;
	t_gnli		*inst;

	if (s == 0)
		return (0);
	if (!(iitem = ft_lstnew(NULL, 0)))
		return (-1);
	if (!(iitem->content = malloc(sizeof(t_gnli))))
	{
		free(iitem);
		return (-1);
	}
	inst = ((t_gnli*)(iitem->content));
	if (!(inst->extra = malloc(s)))
	{
		free(iitem->content);
		free(iitem);
		return (-1);
	}
	inst->fd = fd;
	inst->size = s;
	ft_memcpy(inst->extra, extra, s);
	ft_lstadd(ilist, iitem);
	return (0);
}

/*
** Fill the buffers read() would fill and return, with the data
** from the previous call, so you can just use those like if read() have
** been called.
** Also clear the buffer.
*/

static int		pop_remains(t_list **ilist, const int fd, char *b, int *amnt)
{
	t_list		*iitem;
	t_gnli		*inst;

	iitem = find_iitem(ilist, fd, 1);
	ft_bzero(b, BUFF_SIZE);
	if (iitem == NULL)
	{
		*amnt = 0;
		return (0);
	}
	else
	{
		inst = ((t_gnli*)(iitem->content));
		*amnt = inst->size - 1;
		ft_memcpy(b, inst->extra, inst->size);
		free(inst->extra);
		free(inst);
		free(iitem);
		return (1);
	}
}

/*
** Append srclen characters from src to the end of *dst,
** realocating it so it's big enought to hold the result.
*/

static int		maybe_append(char **dst, char *src, int srclen)
{
	char		*prev_dst;
	int			new_size;

	if (*dst == NULL)
		*dst = ft_strdup("");
	if (*dst == NULL)
		return (-1);
	if (srclen == 0)
		return (0);
	prev_dst = *dst;
	new_size = ft_strlen(*dst) + srclen + 1;
	(*dst) = malloc(new_size);
	if (*dst == NULL)
		return (-1);
	(*dst)[0] = '\0';
	ft_strcpy(*dst, prev_dst);
	ft_strlcat(*dst, src, new_size);
	free(prev_dst);
	return (0);
}

/*
** get_next_line
**
** Read a file descriptor line by line.
** This version keep track of different fd, so you can call it with
** several ones in any order.
** Please read files to their end if you want all memory to be freed,
** or do a call for the fd after closing the file.
*/

int				get_next_line(const int fd, char **line)
{
	static t_list		*ilist = NULL;
	char				buffer[BUFF_SIZE];
	int					amount;
	int					llen;

	if (line == NULL)
		return (-1);
	llen = pop_remains(&ilist, fd, buffer, &amount) ? -2 : 0;
	*line = NULL;
	while (llen < 0 || (amount = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		llen = 0;
		while (llen < amount && buffer[llen] != '\n')
			llen++;
		if (maybe_append(line, buffer, llen) < 0)
			return (-1);
		if (llen < amount - 1)
			set_extra(&ilist, fd, &buffer[llen + 1], amount - llen);
		if (llen < amount)
			return (1);
	}
	if (amount < 0)
		return (-1);
	return ((*line == NULL) ? 0 : 1);
}
