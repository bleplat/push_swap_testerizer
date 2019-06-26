/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpopslashes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:38:10 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/01 09:11:32 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Remove ending slash, returning how many where removed.
*/

int				ft_strpopslashes(char *path)
{
	char	*end;
	int		count;

	if (!path)
		return (0);
	end = path;
	while (*end != '\0')
		end++;
	count = 0;
	while (path < end)
	{
		end--;
		if (*end == '/')
		{
			*end = '\0';
			count++;
		}
		else
			return (count);
	}
	return (count);
}
