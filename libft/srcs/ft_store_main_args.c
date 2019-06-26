/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_main_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:27:24 by bleplat           #+#    #+#             */
/*   Updated: 2019/05/07 20:49:29 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Statically store the arguments of the main() function.
** First time call store the values, next calls retrieve them.
*/

void		ft_store_main_args(int *argc, char ***argv, char ***envp)
{
	static int		store_argc = -1;
	static char		**store_argv = 0;
	static char		**store_envp = 0;

	if (store_argc == -1)
	{
		store_argc = 0;
		if (argc != 0)
			store_argc = *argc;
		if (argv != 0)
			store_argv = *argv;
		if (envp != 0)
			store_envp = *envp;
		return ;
	}
	if (argc != 0)
		*argc = store_argc;
	if (argv != 0)
		*argv = store_argv;
	if (envp != 0)
		*envp = store_envp;
}
