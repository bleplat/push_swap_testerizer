/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hrbytes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:27:35 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/10 21:02:31 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		putfull(char *dst, long long int nb)
{
	if (nb > 999)
		nb = 999;
	dst[2] = '0' + (nb % 10);
	nb /= 10;
	dst[1] = '0' + (nb % 10);
	nb /= 10;
	dst[0] = '0' + (nb % 10);
}

static void		put(char *dst, long long int unit, long long int deci)
{
	if (unit > 9)
		putfull(dst, unit);
	else
	{
		dst[0] = '0' + (unit % 10);
		dst[1] = '.';
		dst[2] = '0' + ((deci * 10 / 1024) % 10);
	}
}

/*
** Put a byte count as human readable representation in a 5 bytes len buffer,
** terminating it with '\0' so its content become:
** n.dU\0
*/

void			ft_hrbytes(char *buf5b, long long int bytes)
{
	long long int		unit;
	long long int		deci;
	int					suff;

	suff = 0;
	deci = 0;
	unit = bytes;
	while (unit > 999 && suff < 9)
	{
		deci = unit % 1024;
		unit = unit / 1024;
		suff += 1;
	}
	put(buf5b, unit, deci);
	buf5b[3] = "BKMGTPEZY?"[(suff > 8) ? 8 : suff];
	buf5b[4] = '\0';
}
