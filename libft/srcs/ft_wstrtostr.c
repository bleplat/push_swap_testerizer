/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 19:44:29 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/27 18:56:11 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

static inline void	pasting(unsigned char *new_str, wchar_t *wstr, int max_b)
{
	int				bytes_count;
	unsigned char	*curr;
	int				i_wchr;

	bytes_count = 0;
	curr = new_str;
	i_wchr = 0;
	while (wstr[i_wchr] != 0)
	{
		bytes_count += ft_wchrlen(wstr[i_wchr]);
		if (max_b >= 0 && bytes_count > max_b)
			return ;
		while (*curr != '\0')
			curr++;
		ft_wchrtostr(curr, wstr[i_wchr]);
		i_wchr++;
	}
}

/*
** Translates a wide string to a string.
** If 'max_bytes' is at least 0, the output is limited to 'max_bytes' bytes.
*/

unsigned char		*ft_wstrtostr(wchar_t *wstr, int max_bytes)
{
	int				chr_needs;
	unsigned char	*new_str;
	int				i_wchr;

	chr_needs = 0;
	i_wchr = 0;
	while (wstr[i_wchr] != 0)
	{
		chr_needs += ft_wchrlen(wstr[i_wchr]);
		i_wchr++;
	}
	if (max_bytes >= 0 && chr_needs > max_bytes)
		chr_needs = max_bytes;
	if (!(new_str = (unsigned char*)ft_strnew(chr_needs)))
		return (NULL);
	pasting(new_str, wstr, max_bytes);
	return (new_str);
}
