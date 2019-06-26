/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:11:43 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/23 11:29:43 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** /!\ UNTESTED /!\
*/

int		ft_strpop(const char *source, const char *search)
{
	int			len;

	len = 0;
	while (*source == *search)
	{
		if (*source == '\0')
			return (len);
		source++;
		search++;
		len++;
	}
	return (0);
}
