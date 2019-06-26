/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:06:22 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 18:53:12 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HELPERS_H
# define FT_PRINTF_HELPERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include "libft_array.h"
# include "libft_types.h"

# include "ft_printf_types.h"

/*
** ft_*printf
** ft_printf_wrapped_entry
** ft_printf*
**
** Users may call any 'ft_*printf' functions. They are all wrappers to the
** 'ft_printf_wrapped_entry' function.
** There is 3 steps in this algorithm:
** 1: Parting
**   Parse the format to get a list of its components, aka 't_printf_rstpart'.
** 2: Formating
**   Process all components to get only strings to concatenate.
** 3: Concate
**   Retrieve the full string from all the string components.
*/

int		ft_printf_wrapped_entry(char **ret, const char *fmt, va_list ap);

/*
** Fonctions called directly from the 'ft_printf_wrapped_entry', in this order:
*/

t_array	*ft_printf_rstparts_get(const char *fmt);
char	*ft_printf_rstparts_fuse(t_array *parts_a);
int		ft_printf_rstparts_clean(t_array **parts_a);

/*
** Parse format components (rstparts) one by one.
** Parse a single rstpart from a format, and set next_fmt to point at
** the begining of the next rstpart to be parsed from the format.
** ~_percent and ~_bracket are used for specific cases.
** Other functions are parsing helpers.
*/

int		ft_printf_nextrstpart(
			char **next_fmt, char *fmt, t_printf_rstpart *part);
int		ft_printf_nextrstpart_percent(
			char **next_fmt, char *fmt, t_printf_rstpart *part);
int		ft_printf_nextrstpart_bracket(
			char **next_fmt, char *fmt, t_printf_rstpart *part);

int		ft_printf_popstr(char **format, const char *str);
int		ft_printf_popchar(char **format, char c);
int		ft_printf_popint(int *cr_int, char **format);
int		ft_printf_w_or_p(int *cr_int, int *v, int *v_iap, char **fmt);

void	ft_printf_addconvmod_dinoux(unsigned int *conversion, char **len_mods);
void	ft_printf_addconvmod_aefg(unsigned int *conversion, char **len_mods);
void	ft_printf_addconvmod_cs(unsigned int *conversion, char **len_mods);
int		ft_printf_addoptionflag(int *options, char **fmt);

/*
** Creating a vector of va_list to iterate easily over:
*/

int		ft_printf_getmaxap(t_printf_rstpart *parts, int pcount);
int		ft_printf_getapconv(int i_ap, t_printf_rstpart *parts, int pcount);
void	ft_printf_skipva(int conversion, struct s_va_list_container *cva);
int		ft_printf_apvect(t_va_list_c **aps, t_array *parts_a, va_list ap);
void	ft_printf_endapvect(t_va_list_c **aps, int ap_max);

/*
** Formating level 0 (loop over each):
*/

int		ft_printf_formatall(t_array *parts_a, va_list ap);
int		ft_printf_format(t_printf_rstpart *part, va_list ap, int offset);

/*
** Formating level 1 (first split):
*/

int		ft_printf_format_integer(t_printf_rstpart *part, va_list ap);
int		ft_printf_format_float(t_printf_rstpart *part, va_list ap);
int		ft_printf_format_other(t_printf_rstpart *part, va_list ap);

/*
** Formating level 2 (final selection):
*/

int		ft_printf_format_unknow(t_printf_rstpart *part, va_list ap);
int		ft_printf_format_n(t_printf_rstpart *part, va_list ap, int cnt);

int		ft_printf_format_s(t_printf_rstpart *part, va_list ap);
int		ft_printf_format_c(t_printf_rstpart *part, va_list ap);
int		ft_printf_format_p(t_printf_rstpart *part, va_list ap);
int		ft_printf_format_y(t_printf_rstpart *part, va_list ap);
int		ft_printf_format_r(t_printf_rstpart *part, va_list ap);

int		ft_printf_format_sints(t_printf_rstpart *part, va_list ap);
int		ft_printf_format_uints(t_printf_rstpart *part, va_list ap);

/*
** Formating helpers:
*/

char	ft_printf_get_sign_char(t_printf_rstpart *part);
int		ft_printf_adjust_field(t_printf_rstpart *part);
int		ft_printf_prefix_int(t_printf_rstpart *part);
int		ft_printf_prefix_float(t_printf_rstpart *part);

t_ull	ft_printf_readva_uint(unsigned int conversion, va_list ap);
t_sll	ft_printf_readva_sint(unsigned int conversion, va_list ap);
t_ld	ft_printf_readva_float(unsigned int conversion, va_list ap);

#endif
