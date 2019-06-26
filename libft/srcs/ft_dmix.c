/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dmix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:26:37 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/07 14:27:54 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double				ft_dmix(double x, double y, double a)
{
	return (x * (1 - a) + y * a);
}
