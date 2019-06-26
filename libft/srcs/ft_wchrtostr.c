/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:45:08 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/03 21:35:35 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** Return how many characters are needed to stro this wide char as a char*
** representation.
*/

int				ft_wchrlen(wchar_t wchr)
{
	if (wchr < 0x80)
		return (1);
	else if (wchr < 0x800)
		return (2);
	else if (wchr < 0x10000)
		return (3);
	else if (wchr < 0x110000)
		return (4);
	else
		return (0);
}

/*
** Translate a wide char to the corresponding string.
** Output into 'dst'.
** This do not terminate the result with a zero!
*/

void			ft_wchrtostr(unsigned char *dst, wchar_t wchr)
{
	if (wchr < 0x80)
		dst[0] = wchr;
	else if (wchr < 0x800)
	{
		dst[0] = ((wchr >> 6) & 0x1F) | 0xC0;
		dst[1] = ((wchr >> 0) & 0x3F) | 0x80;
	}
	else if (wchr < 0x10000)
	{
		dst[0] = ((wchr >> 12) & 0xF) | 0xE0;
		dst[1] = ((wchr >> 6) & 0x3F) | 0x80;
		dst[2] = ((wchr >> 0) & 0x3F) | 0x80;
	}
	else if (wchr < 0x110000)
	{
		dst[0] = ((wchr >> 18) & 0x7) | 0xF0;
		dst[1] = ((wchr >> 12) & 0x3F) | 0x80;
		dst[2] = ((wchr >> 6) & 0x3F) | 0x80;
		dst[3] = ((wchr >> 0) & 0x3F) | 0x80;
	}
}
