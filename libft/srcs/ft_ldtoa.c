/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:55:40 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/27 20:19:18 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				reversed_round_to_even(char *str)
{
	while (1)
	{
		if (*str == '.')
			str++;
		if (*str == '\0')
		{
			*str = '1';
			return ;
		}
		else
		{
			*str += 1;
			if (*str > '9')
				*str = '0';
			else
				return ;
		}
		str++;
	}
}

static char			pop_dg(long double *d, int digit_loc)
{
	long double	destroyed;
	char		digit;

	destroyed = *d / (long double)ft_llpow(10, digit_loc);
	digit = (char)destroyed;
	*d -= (long double)digit * (long double)ft_llpow(10, digit_loc);
	return ('0' + digit);
}

static int			len_needs(long double d, unsigned int precision)
{
	int	len;

	len = 0;
	if (d < 0)
	{
		len++;
		d *= -1;
	}
	while (d >= 10.0)
	{
		len++;
		d /= 10;
	}
	len += 3 + precision + 2;
	return (len);
}

static char			*ft_ldtoa_p2(long double *d,
								unsigned int precision,
								char *rst)
{
	int				left;
	char			c;

	left = ft_ldsize(*d) - 1;
	while (left >= 0)
	{
		c = pop_dg(d, left);
		ft_strputchr(rst, c);
		left--;
	}
	if (precision == 0)
		return (rst);
	ft_strputchr(rst, '.');
	while (precision > 0)
	{
		(*d) *= 10;
		c = pop_dg(d, 0);
		ft_strputchr(rst, c);
		precision--;
	}
	return (rst);
}

/*
** Get a string representation of long double 'd',
** with 'precision' decimal digits.
*/

char				*ft_ldtoa(long double d, unsigned int precision)
{
	char				*rst;
	long double			sign;

	if (ft_ldspecial(d, &rst))
		return (rst);
	d *= (sign = ft_ldsign(d));
	if (!(rst = ft_strnew(len_needs(d, precision))))
		return (NULL);
	rst = ft_ldtoa_p2(&d, precision, rst);
	ft_strrev(rst);
	if (d > 0.5 || (d == 0.5 && (ft_strchr("13579", rst[0]))))
		reversed_round_to_even(rst);
	if (sign == -1.0)
		ft_strputchr(rst, '-');
	ft_strrev(rst);
	return (rst);
}
