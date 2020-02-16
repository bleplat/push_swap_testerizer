/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hcolortoansi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 10:56:29 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/15 01:08:17 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int		thatcolor(int *color, char **cur, const char *c, int v)
{
	int		res;

	if ((res = ft_alnumpop(*cur, c)) != 0)
		*color += v;
	*cur += res;
	return (res);
}

static int				common(int *color, char **cur)
{
	int		res;

	res = 0;
	res += thatcolor(color, cur, "black", 0);
	res += thatcolor(color, cur, "red", 1);
	res += thatcolor(color, cur, "maroon", 1);
	res += thatcolor(color, cur, "green", 2);
	res += thatcolor(color, cur, "yellow", 3);
	res += thatcolor(color, cur, "olive", 3);
	res += thatcolor(color, cur, "blue", 4);
	res += thatcolor(color, cur, "navy", 4);
	res += thatcolor(color, cur, "magenta", 5);
	res += thatcolor(color, cur, "cyan", 6);
	res += thatcolor(color, cur, "teal", 6);
	res += thatcolor(color, cur, "white", 7);
	res += thatcolor(color, cur, "orange", 208);
	res += thatcolor(color, cur, "purple", 91);
	res += thatcolor(color, cur, "pink", 205);
	res += thatcolor(color, cur, "lime", 40);
	res += thatcolor(color, cur, "orangered", 202);
	res += thatcolor(color, cur, "brown", 94);
	res += thatcolor(color, cur, "tan", 223);
	return (res);
}

static int				effect(char **cur)
{
	char		*last;

	last = *cur;
	if ((*cur += ft_alnumpop(*cur, "eoc")) - last)
		return ((int)(1 + (*cur = ft_strdup("\e[0m"))));
	if ((*cur += ft_alnumpop(*cur, "reset")) - last)
		return ((int)(1 + (*cur = ft_strdup("\e[0m"))));
	if ((*cur += ft_alnumpop(*cur, "normal")) - last)
		return ((int)(1 + (*cur = ft_strdup("\e[21m\e[23m\e[24m\e[29"))));
	if ((*cur += ft_alnumpop(*cur, "bold")) - last)
		return ((int)(1 + (*cur = ft_strdup("\e[1m"))));
	if ((*cur += ft_alnumpop(*cur, "dim")) - last)
		return ((int)(1 + (*cur = ft_strdup("\e[2m"))));
	if ((*cur += ft_alnumpop(*cur, "italic")) - last)
		return ((int)(1 + (*cur = ft_strdup("\e[3m"))));
	if ((*cur += ft_alnumpop(*cur, "underline")) - last)
		return ((int)(1 + (*cur = ft_strdup("\e[4m"))));
	if ((*cur += ft_alnumpop(*cur, "strike")) - last)
		return ((int)(1 + (*cur = ft_strdup("\e[9m"))));
	if ((*cur += ft_alnumpop(*cur, "strikeout")) - last)
		return ((int)(1 + (*cur = ft_strdup("\e[9m"))));
	return (0);
}

/*
** Proceed a single code word.
** return 1 if the final result got put in *cur.
*/

static int				single(int *color, int *flags, char **cur)
{
	int			rst;
	char		*last;

	last = *cur;
	rst = 0;
	if (effect(cur))
		return (1);
	else if ((*cur += ft_alnumpop(*cur, "back")) - last)
		*flags |= FT_ANSICOLOR_FLAG_BACKGROUND;
	else if ((*cur += ft_alnumpop(*cur, "bright")) - last)
		*color += 8;
	else if ((*cur += ft_alnumpop(*cur, "light")) - last)
		*color += 8;
	else if (!common(color, cur))
	{
		*color = ft_atoi(*cur);
		while (ft_isalnum(**cur) || **cur == '-')
			*cur += 1;
	}
	return (0);
}

/*
** Get an escape code for an human color string ending by '\0' or '}'.
** Format: [bright|light] [black|red|green...orange|purple] [back]
** If format is not correct, behavior is undefined.
*/

char					*ft_hcolortoansi(const char *hcolor)
{
	int			color;
	int			flags;
	char		*cur;
	int			nempty;

	nempty = 0;
	color = 0;
	flags = 0;
	cur = (char*)hcolor;
	while (*cur != '}' && *cur != '\0')
	{
		if (*cur == '}' || *cur == '\0')
			break ;
		nempty = 1;
		if (single(&color, &flags, &cur))
			return (cur);
		while (*cur != '}' && *cur != '\0' && !ft_isalnum(*cur))
			cur++;
	}
	if (nempty)
		return (ft_ansicolor(color, flags));
	else
		return (ft_strdup("\e[0m"));
}
