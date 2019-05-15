/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:48:39 by bleplat           #+#    #+#             */
/*   Updated: 2019/05/15 19:19:46 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdint.h>

int		main(int argc, char **argv)
{
	long				ms;
	time_t				s;
	struct timespec		spec;

	(void)argc;
	(void)argv;
	clock_gettime(CLOCK_REALTIME, &spec);
	s = spec.tv_sec;
	ms = round(spec.tv_nsec / 1.0e6);
	if (ms > 999)
	{
		s++;
		ms = 0;
	}
	printf("%ju.%03ld\n", (uintmax_t)s, ms);
	return (0);
}
