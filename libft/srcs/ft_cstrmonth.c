/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstrmonth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 07:25:23 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 19:13:50 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char		*ft_cstrmonth(int month)
{
	static char *monthes[12] = { "Jan", "Feb", "Mar",
								"Apr", "May", "Jun",
								"Jul", "Aug", "Sep",
								"Oct", "Nov", "Dec"};

	if (month < 0 || month > 12)
		return ((void*)0);
	else
		return (monthes[month]);
}
