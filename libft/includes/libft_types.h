/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:57:30 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 18:32:25 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYPES_H
# define LIBFT_TYPES_H

# include <sys/stat.h>

/*
** I n t e g e r s
*/

# define FT_INT32_MIN -2147483648
# define FT_INT32_MAX 0x7FFFFFFF

typedef char								t_sbyte;
typedef unsigned char						t_ubyte;

typedef short								t_short;
typedef unsigned short						t_ushort;

typedef int									t_int;
typedef unsigned int						t_uint;

typedef long int							t_lint;
typedef unsigned long int					t_ulint;

typedef long long int						t_llint;
typedef unsigned long long int				t_ullint;

typedef signed long long					t_sll;
typedef unsigned long long					t_ull;

/*
** F l o a t s
*/

typedef float								t_f;
typedef double								t_lf;
typedef double								t_d;
typedef long double							t_ld;
typedef long double							t_llf;

/*
** O t h e r
*/

typedef struct stat							t_stat;
typedef char								*t_lscolors;

#endif
