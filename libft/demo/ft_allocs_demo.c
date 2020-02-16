/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocs_demo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 22:20:59 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/16 13:56:57 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

/*
** This is used to test the LibftMo library, present in this libft.
** Because LibftMo is used to find memory leaks, this program will
** leak ON PURPOSE.
**
** see 'make ftmo_help'.
*/

void			alloc(int argc, char **argv, int i)
{
	void	*mem;
	char	*size_str;
	int		rem;
	int		plus;

	if (i >= argc)
		return ;
	size_str = argv[i];
	rem = 0;
	if (size_str[0] == '-')
	{
		rem = 1;
		size_str = size_str + 1;
	}
	plus = 0;
	if ((i + 1 < argc) && argv[i + 1][0] == '+' && argv[i + 1][1] == '\0')
		plus = 1;
	mem = ft_strnew(ft_atoi(size_str));
	ft_putstr("Allocated some memory...\n");
	if (plus == 1)
		alloc(argc, argv, i + 2);
	if (rem == 0)
		free(mem);
	if (plus == 0)
		alloc(argc, argv, i + 1);
}

int				main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_printf("usage: %s [ + | [-]malloc_size ] ...\n", argv[0]);
		ft_printf("\t+:       + consecutive allocs.\n");
		ft_printf("\tmalloc:  prefix with - to not free memory.\n");
	}
	alloc(argc, argv, 1);
	return (argc - 1);
}
