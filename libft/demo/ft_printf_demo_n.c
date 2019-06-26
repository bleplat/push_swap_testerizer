/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_demo_n.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 22:16:42 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/27 22:16:44 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int				main(int argc, char **argv)
{
	int			w;
	int			x;
	long int	y;
	int			z;
	int			e;

	(void)argc;
	(void)argv;
	ft_printf("%n---%n%s%n$%n@@@@%n\n", &w, &x, "#####", &y, &z, &e);
	ft_printf("before '-' chars, %d chars where printed.\n", w);
	ft_printf("before '#' chars, %d chars where printed.\n", x);
	ft_printf("before '$' chars, %ld chars where printed.\n", y);
	ft_printf("before '@' chars, %d chars where printed.\n", z);
	ft_printf("finaly, %d chars where printed.\n", e);
	return (x);
}
