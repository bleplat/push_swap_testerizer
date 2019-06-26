/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmo_log.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:40:13 by bleplat           #+#    #+#             */
/*   Updated: 2019/05/14 17:04:39 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libftmo.h"

void			ftmo_putnbr_fd(long long n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
		ftmo_putnbr_fd(n / 10, fd);
	write(fd, &("0123456789"[n % 10]), 1);
}

void			ftmo_putptr_fd(unsigned long long n, int fd)
{
	if (n >= 16)
		ftmo_putptr_fd(n / 16, fd);
	write(fd, &("0123456789abcdef"[n % 16]), 1);
}

static int		ftmo_log_setup(int file_d)
{
	write(file_d, "\t\t\t\t\t\t\t\t", 8);
	write(file_d, "\e[33mFTMO READY AND LOGGING\e[0m\n", 32);
	return (file_d);
}

/*
** Called to log ftmo events.
** Setup by calling it with func = FTMO_FUNC_SETUP.
** size if not -1 represent a file descriptor.
*/

void			ftmo_log(int func, int size, void *addr)
{
	static int		file_d = -98;

	if (func == FTMO_FUNC_SETUP)
		file_d = ftmo_log_setup(size);
	else if (file_d < 0)
		return ;
	else
	{
		write(file_d, (func == FTMO_FUNC_MALLOC) ? "\e[9" : "\e[3", 3);
		write(file_d, (addr == (void*)0) ? "5m" : "2m", 2);
		if (file_d == 1 || file_d == 2)
			write(file_d, "\t\t\t\t\t\t\t\t", 8);
		if (func == FTMO_FUNC_MALLOC)
		{
			write(file_d, "[malloc] size: ", 16);
			ftmo_putnbr_fd(size, file_d);
		}
		if (func == FTMO_FUNC_FREE)
			write(file_d, "[free]          ", 17);
		write(file_d, "\taddress: 0x", 12);
		ftmo_putptr_fd((unsigned long long)addr, file_d);
		write(file_d, "\n\e[0m", 5);
	}
}
