/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_demo_n.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 22:16:42 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/27 22:28:36 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int				main(int argc, char **argv)
{
	static char		*data = "Some \x01\x02hAArdd \x9f coded\x82 non-asc\xd1ii";

	ft_printf("With %%s:  \"%s\"\n", data);
	ft_printf("With %%r:  \"%r\"\n", data);
	ft_printf("With %%#r: \"%#r\"\n", data);
	return (0);
}
