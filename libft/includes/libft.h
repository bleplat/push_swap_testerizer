/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:59:30 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/17 19:58:13 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>

# include "libft_types.h"
# include "libft_array.h"
# include "libft_readline.h"
# include "libft_files.h"

# include "get_next_line.h"
# include "ft_printf.h"

# define FT_PI 3.14159265359

# define FT_FREETASK_1ST 0x1
# define FT_FREETASK_2ND 0x2
# define FT_FREETASK_BOTH 0x3
# define FT_FREETASK_ALWAY 0x4

# define FT_ANSICOLOR_FLAG_BACKGROUND 0x1
# define FT_ANSICOLOR_FLAG_RGB 0x2

# define FT_READTONL_MALLOC_FAILED -3
# define FT_READTONL_LINE_TOO_LONG -2

/*
** L i b f t   P a r t   I
*/

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *hay, const char *need, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
** L i b f t   P a r t   II
*/

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(const char *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putxnbr_fd(unsigned long long n, int fd);

/*
** C h a i n e d   l i s t s
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *newe);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstlast(t_list *list);
int				ft_lstcount(t_list *list);
t_list			*ft_lstindex(t_list	*list, size_t index);
t_list			*ft_strlstsplit(char const *str, char c);
void			*ft_lstfold(t_list *lst, void *(*f)(void *e1, void *e2));
t_list			*ft_lstpop(t_list **list, t_list *item);

/*
** M a t h
*/

int				ft_min(int a, int b);
int				ft_max(int a, int b);
int				ft_abs(int nb);
int				ft_pow(int nb, unsigned int p);
int				ft_sqrt(int nb);
int				ft_intsize(int i);
t_llint			ft_llpow(t_llint nb, unsigned int p);
long double		ft_ldsign(long double d);
int				ft_ldsize(long double d);
void			ft_swapint(int *a, int *b);
void			ft_swapptr(void **a, void **b);
double			ft_dclamp(double x, double min, double max);
double			ft_dmix(double x, double y, double a);

/*
** I n t s
*/

int				*ft_intsrange(int min, int count, int step);
int				*ft_intsrangeop(int min, int count, int step, char op);
void			ft_intsshuffle(int *array, int count);
void			ft_intsnshuffle(int *array, int count, int shuffles_count);
void			ft_putints(const int *array, int count, const char *sep);
void			ft_intsrot(int *array, int count, int rotation);

/*
** C o n v e r t i o n
*/

int				ft_atoi32check(int *out, const char *str);
char			*ft_lltoa(long long int n);
char			*ft_ulltoa_basestr(unsigned long long int n, char *base_str);
char			*ft_ldtoa(long double d, unsigned int precision);
int				ft_ldspecial(long double d, char **may_out);
void			ft_hrbytes(char *buf5b, long long int bytes);

/*
** S t r i n g s
*/

int				ft_isblank(int c);
int				ft_iscntrl(int c);
int				ft_isspace(int c);
int				ft_isxdigit(int c);
int				ft_isupper(int c);
int				ft_isstrnum(const char *str);
int				ft_strbegins(const char *s1, const char *s2);
int				ft_strends(const char *s1, const char *s2);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strtolower(const char *str);
char			*ft_strtoupper(const char *str);
void			ft_strcatchar(char *str, char c);
void			ft_strputchr(char *str, char c);
char			*ft_strfuse(char **s1, char **s2, int free_task);
char			*ft_strminfield(const char *str, int field_width);
char			*ft_strminfieldc(const char *str, int field_width, char c);
char			*ft_stranychr(const char *s, const char *cs);
void			ft_strtoupper_inplace(char *str);
int				ft_alnumcmp(const char *s1, const char *s2);
int				ft_strpop(const char *source, const char *search);
int				ft_alnumpop(const char *source, const char *s2);
void			ft_strrev(char *str);
int				ft_strpopnls(char *str);
int				ft_putstrvec(const char **vec, int count, const char *sep);
int				ft_dputstrvec(int fd, const char **vec,
								int count, const char *sep);

/*
** U n i c o d e
*/

int				ft_putwchar_fd(wchar_t chr, int fd);
int				ft_putwchar(wchar_t chr);
int				ft_putwstr_fd(const wchar_t *str, int fd);
int				ft_putwstr(const wchar_t *str);
int				ft_wstrlen(const wchar_t *str);
int				ft_wchrlen(wchar_t wchr);
void			ft_wchrtostr(unsigned char *dst, wchar_t wchr);
unsigned char	*ft_wstrtostr(wchar_t *wstr, int max_bytes);

/*
** C o l o r s
*/

int				ft_argb(int a, int r, int g, int b);
int				ft_colorwheel(int degrees);
int				ft_mixcolors(int c0, int c1, double rate);
char			*ft_ansicolor(int color, int flags);
char			*ft_hcolortoansi(const char *hcolor);

/*
** R a n d o m
*/

int				ft_random(void);
unsigned int	ft_urandom(void);
t_llint			ft_llrandom(void);
t_ullint		ft_ullrandom(void);

/*
** A u t o f r e e
*/

const void		*ft_autofree_pushpop(const void *to_push);
int				ft_autofree_begin(void);
void			*ft_autofree(const void *to_free);
void			ft_autofree_end(void);
int				ft_autofree_end0(void);
void			ft_autofree_abort(void);
int				ft_autofree_abort0(void);

/*
** M e m o r y
*/

int				ft_memdel0(void **to_free);
int				ft_memdel1(void **to_free);
int				ft_free0(void *to_free);
void			*ft_freen(void *to_free);
int				ft_ptrcount(void **ptr);
int				ft_memrealloc(void **mem, size_t *prev_size, size_t new_size);
void			*ft_memdup(const void *s1, size_t size);
int				ft_vecdel(void **vec, int deep);
int				ft_vecdel0(void **vec, int deep);

/*
** V a r i a d i c
*/

void			*ft_va_as_ptr(va_list ap);
char			ft_va_as_char(va_list ap);
short			ft_va_as_short(va_list ap);
int				ft_va_as_int(va_list ap);
long			ft_va_as_long(va_list ap);
long long		ft_va_as_longlong(va_list ap);
double			ft_va_as_double(va_list ap);
long double		ft_va_as_longdouble(va_list ap);
intmax_t		ft_va_as_intmax(va_list ap);
ptrdiff_t		ft_va_as_ptrdiff(va_list ap);
size_t			ft_va_as_size(va_list ap);
wchar_t			ft_va_as_wchar(va_list ap);
unsigned char	ft_va_as_uchar(va_list ap);
unsigned short	ft_va_as_ushort(va_list ap);
unsigned int	ft_va_as_uint(va_list ap);
unsigned long	ft_va_as_ulong(va_list ap);
t_ullint		ft_va_as_ulonglong(va_list ap);

/*
** O t h e r
*/

int				ft_welcome(void);
int				ft_goodbye(void);
const void		*ft_pushpop(const void *to_push);
int				ft_pause(void);
int				ft_readtonl(int fd, char **p_dst, int max_line_size);
const char		*ft_cstrmonth(int month);
void			ft_clear(void);
void			ft_store_main_args(int *argc, char ***argv, char ***envp);

#endif
