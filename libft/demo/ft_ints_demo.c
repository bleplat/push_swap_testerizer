/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ints_demo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:46:37 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/17 20:50:46 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				usage(char *program_name)
{
	ft_printf("Usage: %s ", program_name);
	ft_putstr("min count [step] [shuffle] [sep]\n");
	ft_putstr("\tmin\tMinimum number to output.\n");
	ft_putstr("\tcount\tHow many numbers to output.\n");
	ft_putstr("\tstep\tInterval between each number.\n");
	ft_putstr("\t\t\tCan be prefixed with '*' or '/' for nonlinear lists.\n");
	ft_putstr("\tshuffle\tHow to shuffle, determined by the given number:\n");
	ft_putstr("\t\t\tn < 0: shuffle the whole list.\n");
	ft_putstr("\t\t\tn = 0: no shuffle.\n");
	ft_putstr("\t\t\tn > 0: perform n random shuffle.\n");
	ft_putstr("\t\t\tn begins with 'r': rotate.\n");
	ft_putstr("\tsep\tString used as a separator. Default ' '.\n");
	return (1);
}

/*
** Only generate an unshuffled list.
*/

int				*generate_list(int argc, char **argv)
{
	int		min;
	int		count;
	int		step;
	char	op;

	min = ft_atoi(argv[1]);
	count = ft_atoi(argv[2]);
	if (argc <= 3)
		step = 1;
	else if (!ft_strchr("-*/%", argv[3][0]))
		step = ft_atoi(argv[3]);
	else
		step = ft_atoi(argv[3] + 1);
	op = (argc > 3) ? argv[3][0] : '+';
	return (ft_intsrangeop(min, count, step, op));
}

/*
** Program to create an integer list, and shuffle it, whole, or more or less.
*/

int				main(int argc, char **argv)
{
	int		*ints;
	int		count;
	int		shuffle;

	if (argc < 3)
		return (usage(argv[0]));
	if (!(ints = generate_list(argc, argv)))
		return (2);
	count = ft_atoi(argv[2]);
	shuffle = (argc > 4) ? ft_atoi(argv[4]) : 0;
	if (shuffle < 0)
		ft_intsshuffle(ints, count);
	else if (argc > 4 && argv[4][0] == 'r')
		ft_intsrot(ints, count, ft_atoi(argv[4] + 1));
	else
		ft_intsnshuffle(ints, count, shuffle);
	ft_putints(ints, count, (argc > 5) ? argv[5] : " ");
	ft_memdel((void**)&ints);
	return (0);
}
