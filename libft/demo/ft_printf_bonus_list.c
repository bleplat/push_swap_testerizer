/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:06:47 by bleplat           #+#    #+#             */
/*   Updated: 2019/05/16 20:06:48 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					main(void)
{
	ft_welcome();
	ft_pause();
	ft_printf("\n{underline}# Bonuses fully added into ft_printf:{}\n");
	ft_printf("{bold}colors as {red}%{red}{} or {italic}%{italic}\n");
	ft_printf("{bold}colors with %%y and %%#y\n");
	ft_printf("{bold}colors with %%Y and %%#Y\n");
	ft_printf("{bold}conv %%n\n");
	ft_printf("{bold}flag *\n");
	ft_printf("{bold}flag $\n");
	ft_printf("{bold}conv %%b and %%B\n");
	ft_printf("{bold}conv %%r\n");
	ft_printf("\n{}{underline}# Bonuses partially added into ft_printf:{}\n");
	ft_printf("dprintf, asprintf, vprintf, vdprintf and vasprintf\n");
	ft_printf("%%S and %%C\n");
	ft_printf("Unknown conversion types\n");
	ft_printf("flags j, t and z\n");
	ft_goodbye();
	ft_pause();
}
