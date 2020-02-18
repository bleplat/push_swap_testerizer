# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleplat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 09:05:04 by bleplat           #+#    #+#              #
#    Updated: 2020/02/16 16:19:12 by bleplat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###########################
###   B I N A R I E S   ###
###########################

NAME_1  =   libft.a
NAME_2  =   libftmo.so
NAME    =   $(NAME_1)_$(NAME_2)_demos
ALL_NAMES = $(NAME_1) $(NAME_2) demos


###########################
###  L I B R A R I E S  ###
###########################

LIBFT_DIR   = .
# LIBFT     = $(LIBFT_DIR)/libft.a
# LIBFTMO   = $(LIBFT_DIR)/libftmo.a


###########################
###    S O U R C E S    ###
###########################

FNT_C =		\

FNT_1 =		ft_welcome.c \
			ft_store_main_args.c \
			ft_clear.c \
			ft_intsrot.c \
			ft_hrbytes.c \
			ft_listxattr.c \
			ft_filecolor.c \
			ft_lscolors.c \
			ft_linkfolow.c \
			ft_strpopslashes.c \
			ft_fileusr.c \
			ft_filegrp.c \
			ft_usrname.c \
			ft_grpname.c \
			ft_cstrmonth.c \
			ft_dirfilepath.c \
			ft_filemode.c \
			ft_strmode.c \
			ft_dputstrvec.c \
			ft_putstrvec.c \
			ft_listdir.c \
			ft_vecdel.c \
			ft_vecdel0.c \
			ft_dclamp.c \
			ft_dmix.c \
			ft_pause.c \
			ft_readtonl.c \
			ft_readline.c \
			ft_intsshuffle.c \
			ft_intsnshuffle.c \
			ft_intsrange.c \
			ft_putints.c \
			ft_strpopnls.c \
			ft_random.c \
			ft_urandom.c \
			ft_llrandom.c \
			ft_ullrandom.c \
			ft_swapint.c \
			ft_swapptr.c \
			ft_atoi.c \
			ft_atoi32check.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isblank.c \
			ft_iscntrl.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_isxdigit.c \
			ft_itoa.c \
			ft_lstadd.c \
			ft_lstcount.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstfold.c \
			ft_lstindex.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_max.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memdup.c \
			ft_memmove.c \
			ft_memrealloc.c \
			ft_memset.c \
			ft_min.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putxnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_sqrt.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strlstsplit.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strndup.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtolower.c \
			ft_strtoupper.c \
			ft_strtrim.c \
			ft_strrev.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_putwchar.c \
			ft_putwchar_fd.c \
			ft_putwstr.c \
			ft_putwstr_fd.c \
			ft_wstrlen.c \
			ft_isstrnum.c \
			ft_strbegins.c \
			ft_strends.c \
			ft_lstpop.c \
			ft_pushpop.c \
			ft_lltoa.c \
			ft_ulltoa_basestr.c \
			ft_strfuse.c \
			ft_autofree_pushpop.c \
			ft_autofree_begin.c \
			ft_autofree.c \
			ft_autofree_end.c \
			ft_autofree_end0.c \
			ft_autofree_abort.c \
			ft_autofree_abort0.c \
			ft_abs.c \
			ft_memdel0.c \
			ft_memdel1.c \
			ft_free0.c \
			ft_freen.c \
			ft_ptrcount.c \
			ft_isupper.c \
			ft_array_new.c \
			ft_array_del.c \
			ft_array_reserve.c \
			ft_array_newitem.c \
			ft_array_shrink.c \
			ft_array_at.c \
			ft_array_clear.c \
			ft_array_reset.c \
			ft_array_removeat.c \
			ft_pow.c \
			ft_llpow.c \
			ft_strcatchar.c \
			ft_ldsize.c \
			ft_ldtoa.c \
			ft_intsize.c \
			ft_strputchr.c \
			ft_strminfield.c \
			ft_stranychr.c \
			ft_strtoupper_inplace.c \
			ft_ldspecial.c \
			ft_ldsign.c \
			ft_va_as_char.c \
			ft_va_as_double.c \
			ft_va_as_int.c \
			ft_va_as_intmax.c \
			ft_va_as_long.c \
			ft_va_as_longdouble.c \
			ft_va_as_longlong.c \
			ft_va_as_ptr.c \
			ft_va_as_ptrdiff.c \
			ft_va_as_short.c \
			ft_va_as_size.c \
			ft_va_as_wchar.c \
			ft_va_as_uchar.c \
			ft_va_as_ushort.c \
			ft_va_as_uint.c \
			ft_va_as_ulong.c \
			ft_va_as_ulonglong.c \
			ft_wchrtostr.c \
			ft_wstrtostr.c \
			ft_argb.c \
			ft_colorwheel.c \
			ft_mixcolors.c \
			ft_ansicolor.c \
			ft_hcolortoansi.c \
			ft_strpop.c \
			ft_alnumcmp.c \
			ft_alnumpop.c \
			ft_printf.c \
			ft_vprintf.c \
			ft_printf_wrapped_entry.c \
			ft_printf_rstparts_get.c \
			ft_printf_nextrstpart.c \
			ft_printf_nextrstpart_percent.c \
			ft_printf_nextrstpart_bracket.c \
			ft_printf_parting_helpers.c \
			ft_printf_apvect.c \
			ft_printf_formatall.c \
			ft_printf_format.c \
			ft_printf_format_unknow.c \
			ft_printf_format_n.c \
			ft_printf_format_ints.c \
			ft_printf_format_floats.c \
			ft_printf_format_others.c \
			ft_printf_format_s.c \
			ft_printf_format_c.c \
			ft_printf_format_p.c \
			ft_printf_format_y.c \
			ft_printf_format_r.c \
			ft_printf_skipva.c \
			ft_printf_readva.c \
			ft_printf_addconvmod.c \
			ft_printf_addoptionflag.c \
			ft_printf_adjust_field.c \
			ft_printf_prefix_int.c \
			ft_printf_prefix_float.c \
			ft_printf_rstparts_fuse.c \
			ft_printf_rstparts_clean.c \
			ft_goodbye.c \

FNT_2 =		ftmo_malloc.c \
			ftmo_free.c \
			ftmo_firstcall.c \
			ftmo_lastcall.c \
			ftmo_getenv.c \
			ftmo_print.c \
			ftmo_should_malloc_succeed.c \
			ftmo_make_reg.c \
			ftmo_track.c \
			ft_isdigit.c \
			ft_atoi.c \
			ft_putchar_fd.c \
			ft_putxnbr_fd.c \
			ft_putstr_fd.c \
			ft_putnbr_fd.c \
			ft_strlen.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_memmove.c \


FNT = $(FNT_1) $(FNT_2)

FNT_DEMO =	ft_allocs_demo \
			ft_atoi32check_demo \
			ft_colorwheel_demo \
			ft_hrbyte_demo \
			ft_ints_demo \
			ft_linkfolow_demo \
			ft_listdir_demo \
			ft_mixcolors_demo \
			ft_printf_bonus_list \
			ft_printf_demo_8ints \
			ft_printf_demo_8ints_asprintf \
			ft_printf_demo_colors \
			ft_printf_demo_n \
			ft_printf_demo_r \
			ft_printf_demo_rgb \
			ft_readline_demo \
			ft_readtonl_demo \


###########################
###    F O L D E R S    ###
###########################

INCLUDES = includes
SRC_DIR  = srcs
OBJ_DIR  = .obj
DEP_DIR  = $(OBJ_DIR)
LIB_DIR  = libs
DEMO_DIR = demo

SRC = $(patsubst %, $(SRC_DIR)/%, $(FNT))
DEP = $(patsubst %, $(DEP_DIR)/%.d, $(FNT))
OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(FNT))
OBJ_C = $(patsubst %, $(OBJ_DIR)/%.o, $(FNT_C))
OBJ_1 = $(patsubst %, $(OBJ_DIR)/%.o, $(FNT_1))
OBJ_2 = $(patsubst %, $(OBJ_DIR)/%.o, $(FNT_2))

SRC_DEMO = $(patsubst %, $(DEMO_DIR)/%.c, $(FNT_DEMO))
OBJ_DEMO = $(patsubst %, $(OBJ_DIR)/$(DEMO_DIR)/%.o, $(FNT_DEMO))
DEMO     = $(patsubst %, $(DEMO_DIR)/%.demo, $(FNT_DEMO))


###########################
###   C O M P I L E R   ###
###########################

CC = gcc

DEFINES = _DARWIN_USE_64_BIT_INODE
CDEFINES = $(patsubst %, -D%, $(DEFINES))

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I $(INCLUDES)
# CFLAGS += -I $(LIBFT_DIR)/includes
LDFLAGS = -L $(LIBFT_DIR) -lft -rdynamic
# LDFLAGS = -L $(LIBFT_DIR) -lftmo


###########################
###      R U L E S      ###
###########################

.PHONY: all
all: $(NAME)

.PHONY: optimized
optimized: CFLAGS += -o3
optimized: all

.PHONY: $(NAME)
$(NAME): $(ALL_NAMES)

$(NAME_1): $(OBJ_C) $(OBJ_1)
	@printf "\e[92m" || true
	ar rc $(NAME_1) $(OBJ_1)
	ranlib $(NAME_1)
	@printf "\e[0m" || true

$(NAME_2): $(OBJ_C) $(OBJ_2)
	@printf "\e[92m" || true
	$(CC) $(CFLAGS) -shared -o $@ $^
	chmod -x $@ || true
	@printf "\e[0m" || true
	make ftmo_help

$(OBJ_DIR):
	@printf "\e[94m" || true
	mkdir -p $@
	@printf "\e[0m" || true

$(OBJ_DIR)/%.o: $(SRC_DIR)/% | $(OBJ_DIR)
	@printf "\e[96m" || true
	$(CC) $(CFLAGS) -o $@ -I $(INCLUDES) -c $<
	@printf "\e[0m" || true

.PHONY: clean
clean:
	@printf "\e[93m" || true
	rm -f $(OBJ)
	rm -rf $(OBJ_DEMO)
	rm -f $(OBJ_DIR)/*.o
	rmdir $(OBJ_DIR) || true
	@printf "\e[0m" || true

.PHONY: fclean
fclean: clean
	@printf "\e[91m" || true
	rm -f $(ALL_NAMES)
	rm -f $(DEMO)
	@printf "\e[0m" || true

.PHONY: re
re: fclean all
	@printf "\e[0m" || true

.PHONY: delete_libs_gits
delete_libs_gits:
	@printf "\e[0m" || true
	@printf "\e[0m" || true

.PHONY: run
run: $(NAME)
	@printf "\e[0m" || true
	@clear
	@./$< || printf "\e[31mFailed to run \"$<\"!\n" || true
	@printf "\e[31mYou cannot run a library!\n" || true


###########################
###  D O C   R U L E S  ###
###########################

display_debug:
	echo $(DEMO_DIR)

.PHONY: demos
demos: $(DEMO)

$(DEMO_DIR)/%.demo: $(OBJ_DIR)/$(DEMO_DIR)/%.o libft.a
	@printf "\e[92m" || true
	gcc $(CFLAGS) -o $@ $< $(LDFLAGS)
	@printf "\e[0m" || true

$(OBJ_DIR)/$(DEMO_DIR): $(OBJ_DIR)
	@printf "\e[94m" || true
	mkdir -p $@
	@printf "\e[0m" || true

$(OBJ_DIR)/$(DEMO_DIR)%.o: $(DEMO_DIR)/%.c | $(OBJ_DIR)/$(DEMO_DIR)
	@printf "\e[96m" || true
	$(CC) $(CFLAGS) -o $@ -I $(INCLUDES) -c $<
	@printf "\e[0m" || true

.PHONY: ftmo_help
ftmo_help:
	@printf "\e[0mWrite the commands below in your shell to get libftmo ready:\n" || true
	@printf "\e[97m" || true
	export FTMO_IGNORES=-1
	export FTMO_MODE=0
	export FTMO_EACH=1
	export FTMO_LOGD=ftmo.log
	@printf "\e[0mOn Linux: \e[97m LD_PRELOAD=libftmo.so ; ./a.out\n" || true
	@printf "\e[0mOn Mac:   \e[97m DYLD_FORCE_FLAT_NAMESPACE=1 ; DYLD_INSERT_LIBRARIES=libftmo.so ; ./a.out\n" || true
	@printf "\e[0mYou should also be alble to link your program with \e[97m-lftmo\n"
	@printf "\e[0mCompiling your program with -rdynamic will enable call stack informations (static functions will not be seen by ftmo)." || true
