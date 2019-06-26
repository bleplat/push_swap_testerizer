/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:21:22 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/08 18:12:58 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strsplit_sizeto(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static int		ft_strsplit2c(char const *s, char c, char **tab, int *count)
{
	int		i_word;
	int		i_letter;
	int		len;

	i_letter = 0;
	i_word = 0;
	while (s[i_letter] != 0)
	{
		while (s[i_letter] == c && s[i_letter] != '\0')
			i_letter++;
		if (s[i_letter] != '\0')
		{
			len = ft_strsplit_sizeto(&s[i_letter], c);
			if (tab != NULL)
			{
				tab[i_word] = ft_strsub(s, i_letter, len);
				if (tab[i_word] == NULL)
					return (0);
			}
			i_word++;
			i_letter += len;
		}
	}
	*count = i_word;
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	int		count;
	char	**tab;

	if (s == NULL)
		return (NULL);
	count = 0;
	if (ft_strsplit2c(s, c, NULL, &count) == 0)
		return (NULL);
	tab = ft_memalloc(sizeof(char *) * (count + 1));
	if (tab != NULL)
	{
		tab[count] = NULL;
		if (ft_strsplit2c(s, c, tab, &count) == 0)
		{
			while (count > 0)
			{
				ft_strdel(&(tab[count - 1]));
				count--;
			}
			ft_memdel((void **)&tab);
		}
	}
	return (tab);
}
