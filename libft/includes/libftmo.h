/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftmo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:36:00 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/15 00:17:07 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTMO_H
# define LIBFTMO_H

# include <stddef.h>

# include "libftmo_region.h"

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
** - FTMO_MODE: Define FTMO behavior.
** - FTMO_IGNORES: The count of malloc to have default behavior
** before using FTMO_EACH.
** - FTMO_EACH: String wich every char represent the result of a malloc.
** 0: failure, 1: success, 2: default, 3: post-default
** - FTMO_LOGD: fd or file to log to. Not working in this version yet.
*/

# define FTMO_BACKTRACE_COUNT 128

/*
** Modes:
**
** 0: [FTMO_IGNORES success] [1 PATTERN] [* success]
** 1: [FTMO_IGNORES fail] [1 PATTERN] [* success]
** 4: [FTMO_IGNORES success] [1 fail] [* success]
** 5: [FTMO_IGNORES fail] [1 success] [* success]
** 8: [FTMO_IGNORES success] [* PATTERN]
**
** Note: modes 4 and 8 are mutualy exclusive.
*/

# define FTMO_MODE_DEFAULT_FAIL 0x1
# define FTMO_MODE_POSTDEFAULT_FAIL 0x2
# define FTMO_MODE_FAIL_ONCE 0x4
# define FTMO_MODE_POSTDEFAULT_REPEAT_EACH 0x8

/*
** Special values for FTMO_IGNORES
*/

# define FTMO_COUNT_INFINITE 2147483647
# define FTMO_INFINITE FTMO_COUNT_INFINITE
# define FTMO_COUNT_GET -2147483647
# define FTMO_COUNT_TRIGGER -2147483648
# define FTMO_CT FTMO_COUNT_TRIGGER

/*
** Messages verbosities.
*/

# define FTMO_INFO 0
# define FTMO_WARN 1
# define FTMO_ERROR -1

/*
** Allocation tracker actions.
*/

# define FTMO_TRACK_MALLOC 6001
# define FTMO_TRACK_FREE 6002
# define FTMO_TRACK_VERIFY 6003
# define FTMO_TRACK_CLEANUP 6004

/*
** Printing and logging.
*/

int			ftmo_putreg(int fd, t_ftmo_region *r);
int			ftmo_log(int v, const char *msg);
int			ftmo_log_p(int v, const char *p, void *pt, const char *s);
int			ftmo_log_r(int v, const char *p, t_ftmo_region *r, const char *s);

/*
** Get env values.
*/

int			ftmo_getenv_mode(void);
int			ftmo_getenv_ignores(void);
int			ftmo_getenv_each(int index, int repeat);
int			ftmo_getenv_logd(int verbosity);

/*
** Overriden functions and replacement.
*/

void		*ftmo_libc_malloc(size_t sz);
void		*malloc(size_t sz);
void		ftmo_libc_free(void *ptr);
void		free(void *ptr);

/*
** Functions called once in ftmo.
*/

int			ftmo_firstcall(void);
void		ftmo_lastcall(void);

/*
** Track mallocs and frees.
*/

int			ftmo_track(int track_action, void *ptr, size_t sz, int mindex);

/*
** Other.
*/

int			ftmo_should_malloc_succeed(int index);

#endif
