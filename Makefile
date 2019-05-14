# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleplat <bleplat@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 09:05:04 by bleplat           #+#    #+#              #
#    Updated: 2019/05/14 20:17:56 by bleplat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####################
###    Config    ###
####################

# PATH TO YOUR PROJET, WITHOUT AN ENDING '/':
TESTED_DIR = ../try0



############################
###    Compile/Rules    ####
############################

# I have to update this to match the libft quality, but now i am lazy...

NAME = tests

INCLUDES = libft/includes
SRC_DIR = .
OBJ_DIR = .
CP_DIR = copyed_project

CFLAGS = -Wall -Wextra
LDFLAGS = -L libft -lft

.PHONY:all
all: import makeproject $(NAME)
	mkdir -p ok_pieces
	./genpieces 1> /dev/null
	chmod 666 ok_pieces/*
	@printf "\e[36mReady to run testerizer.sh!\e[31m\n\n"



###################################
###    Tested Project Import    ###
###################################

.PHONY: norminette
norminette:
	@printf "\e[36mrunning norminette..\e[31m\n"
	@norminette $(TESTED_DIR)/ | sed -e "/^Norme: /d" | sed -e "/^Warning: /d"

.PHONY: import
import: $(CP_DIR)
$(CP_DIR):
	@printf "\e[35mcopying files..\n"
	cp -rn $(TESTED_DIR) $(CP_DIR)

.PHONY: makeproject
makeproject: $(CP_DIR)/push_swap
$(CP_DIR)/push_swap: $(CP_DIR)
	@printf "\e[35mMaking project..\n"
	@sh makeproject.sh $(CP_DIR)

###############################
###    TESTS EXECUTABLES    ###
###############################

TESTS_EXE = gettime

gettime: gettime.c
	gcc $(CFLAGS) -o3 -o $@ $<



###########################
###    Special Rules    ###
###########################

%.o: %.c
	@printf "\e33mnothing in rule to make $@!\n"

$(NAME): $(TESTS_EXE)
	@printf "\e[34mmake finished\n"

clean:
	@printf "\e[35mcleaning...\n"
	rm -rf tmp
	rm -f tmp_*
	rm -rf *.o

fclean: clean
	rm -rf $(CP_DIR) 2> /dev/null
	rm -rf $(NAME)_*
	rm -f test_results
	rm -f gettime
	rm -f genpieces
	rm -rf ok_pieces

re: fclean all
