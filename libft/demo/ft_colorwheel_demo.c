/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorwheel_demo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 19:25:17 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/16 19:39:47 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			main(void)
{
	int a;

	a = 0;
	while (a < 360)
	{
		ft_printf("%Y%d\n", ft_colorwheel(a), a);
		a += 1;
	}
}