/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftmo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:36:00 by bleplat           #+#    #+#             */
/*   Updated: 2019/05/09 23:08:39 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTMO_H
# define LIBFTMO_H

# include <stddef.h>

/*
** libftmo (ft malloc override)
**
** Those functions are used to make malloc fail on purpose.
** This can be used to trigger memory leaks.
** Use without moderation.
**
** This file does not depend on the libft, for the folowing reasons:
** - do not waste my libft performances
** - test leaks on my libft
** - be easy and fast to use in a random project even if not mine
**
** The folowing env variables may be used:
** - FTMO_MODE: Define Default and post-default behavior. Modes can be
** summed together.
** - FTMO_COUNT: Count of malloc() calls until default behavior change.
** At 0, malloc() will fail if default behavior is to run true the malloc.
** - FTMO_EACH: String of 0 (malloc) and 1 (fail) used after behavior change
** to choose what is the result of malloc. Mode 8 needed.
** - FTMO_LOGD: -1 to not log, 1 or 2 to log in standard/error output,
** or a file name.
**
** Recommended FTMO_MODE=10: use FTMO to know when to fail, after FTMO_COUNT
** calls to malloc, then use malloc when no data available in FTMO
*/

# define FTMO_COUNT_INFINITE 2147483647
# define FTMO_INFINITE FTMO_COUNT_INFINITE
# define FTMO_COUNT_GET -2147483647
# define FTMO_COUNT_TRIGGER -2147483648
# define FTMO_CT FTMO_COUNT_TRIGGER

# define FTMO_MODE_FAIL 0x1
# define FTMO_MODE_MALLOC 0x2
# define FTMO_MODE_SWITCH 0x4
# define FTMO_MODE_EACH 0x8
# define FTMO_MODE_TRIGGER 0x400

# define FTMO_FUNC_MALLOC 0x100
# define FTMO_FUNC_FREE 0x200
# define FTMO_FUNC_SETUP 0x800

/*
** Get env values.
*/

int			ftmo_getenv_mode(void);
int			ftmo_getenv_count(void);
int			ftmo_getenv_each(int *out, int index);

/*
** Get/Set/Trigger next count/mode
*/

int			ftmo_count(int new_count);
int			ftmo_mode(int new_mode);

/*
** Internal functions, do not use.
*/

int			ftmo_getenv_logd(void);
void		ftmo_log(int func, int size, void *addr);
int			ftmo_choice(void);

/*
** Overriden functions.
*/

void		*malloc(size_t sz);
void		free(void *ptr);

#endif
