/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpopnls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:38:10 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/04 14:11:30 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Remove ending new libe, returning how many were found.
*/

int				ft_strpopnls(char *str)
{
	char	*end;
	int		count;

	if (!str)
		return (0);
	end = str;
	while (*end != '\0')
		end++;
	count = 0;
	while (str < end)
	{
		end--;
		if (*end == '\n')
		{
			*end = '\0';
			count++;
		}
		else
			return (count);
	}
	return (count);
}
