# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleplat <bleplat@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 09:05:04 by bleplat           #+#    #+#              #
#    Updated: 2019/05/20 16:42:58 by bleplat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####################
###    Config    ###
####################

# PATH TO YOUR PROJET, WITHOUT AN ENDING '/':
TESTED_DIR = ../cfat



############################
###    Compile/Rules    ####
############################

# I have to update this to match the libft quality, but now i am lazy...

NAME = tests

INCLUDES = -I libft/includes
SRC_DIR = .
OBJ_DIR = .
CP_DIR = copyed_project

CFLAGS = -Wall -Wextra $(INCLUDES)
LDFLAGS = -L libft -lft

.PHONY: all
all: makeproject $(NAME)
	@printf "\e[36mReady to run testerizer.sh!\e[31m\n\n"



###################################
###    Tested Project Import    ###
###################################

.PHONY: norminette
norminette:
	@printf "\e[36mrunning norminette..\e[31m\n"
	@sh normproject.sh

.PHONY: import
import: $(CP_DIR)
$(CP_DIR):
	@printf "\e[35mcopying files..\n"
	cp -rn $(TESTED_DIR) $(CP_DIR)
	cat -e $(CP_DIR)/author || cat -e $(CP_DIR)/auteur

.PHONY: makeproject
makeproject: $(CP_DIR)/push_swap
$(CP_DIR)/push_swap: $(CP_DIR)
	@printf "\e[35mMaking project..\n"
	@sh makeproject.sh $(CP_DIR)



###############################
###    TESTS EXECUTABLES    ###
###############################

TESTS_EXE = gettime generator

gettime: gettime.c
	gcc $(CFLAGS) -o3 -o $@ $<

libft/libft.a:
	make -C libft/
generator: libft/demo/ft_ints_demo.c libft/libft.a
	gcc $(CFLAGS) -o3 -o $@ -L./libft -lft $<



###########################
###    Special Rules    ###
###########################

%.o: %.c
	@printf "\e33mnothing in rule to make $@!\n"

$(NAME): $(TESTS_EXE)
	@printf "\e[34mmake finished\n"

.PHONY: clean
clean:
	@printf "\e[35mcleaning...\n"
	rm -rf tmp
	rm -f tmp_*
	rm -rf *.o

.PHONY: fclean
fclean: clean
	rm -rf $(CP_DIR) 2> /dev/null
	rm -rf $(NAME)_*
	rm -rf test_results
	rm -rf gettime
	rm -rf generator
	rm -rf tmp_*
	rm -rf *.tmp

.PHONY: re
re: fclean all
