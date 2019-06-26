/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:06:22 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 18:50:06 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int			ft_printf(const char *format, ...);
int			ft_dprintf(int fd, const char *format, ...);
int			ft_asprintf(char **ret, const char *format, ...);

int			ft_vprintf(const char *format, va_list ap);
int			ft_vdprintf(int fd, const char *format, va_list ap);
int			ft_vasprintf(char **ret, const char *format, va_list ap);

#endif
