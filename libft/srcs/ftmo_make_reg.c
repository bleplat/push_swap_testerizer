/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmo_make_reg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 23:45:03 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/15 00:47:57 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execinfo.h>

#include "libft.h"

#include "libftmo.h"

static void						remove_ftmo(char **ct, int n)
{
	int				i;

	i = 0;
	while (i < n && ct[i])
	{
		if (ft_strstr(ct[i], "libftmo.so") != NULL)
		{
			ct[i] = 0;
			ft_memmove(&ct[i], &ct[i + 1], sizeof(char*) * (n - i - 1));
			ct[n - 1] = 0;
			i--;
		}
		i++;
	}
	ct[n - 1] = 0;
}

t_ftmo_region					ftmo_make_reg(int index, void *ptr, size_t sz)
{
	t_ftmo_region	reg;
	int				nfuncs;
	void			*funcs[FTMO_BACKTRACE_COUNT];

	reg.index = index;
	reg.ptr = ptr;
	reg.size = sz;
	reg.calltree = NULL;
	if (index != -1 && sz >= 0)
	{
		nfuncs = backtrace(funcs, FTMO_BACKTRACE_COUNT);
		if (nfuncs >= 2)
			reg.calltree = backtrace_symbols(funcs, nfuncs);
		if (reg.calltree)
		{
			reg.calltree[nfuncs - 1] = NULL;
			remove_ftmo(reg.calltree, nfuncs);
		}
	}
	return (reg);
}
