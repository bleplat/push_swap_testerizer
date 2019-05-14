# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    normproject.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleplat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 21:09:13 by bleplat           #+#    #+#              #
#    Updated: 2019/05/14 21:14:37 by bleplat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TESTED_DIR="$1"

RST="$(norminette $TESTED_DIR | sed -e '/^Norme: /d' | sed -e '/^Warning: /d')"
EXPECT="$(echo '')"

if [ "$RST" == "" ] || [ "$RST" == "$EXPECT" ] ; then
    printf "\e[32mRan norminette.\n"
	exit 0
else
	printf "\e[31m!!!!!!!!!!!!!!!!!!!!!!!!\n"
	printf "\e[31m!!!    Norm Error    !!!\n"
	printf "\e[31m!!!!!!!!!!!!!!!!!!!!!!!!\n"
	printf "\e[91m%s\n" "$RST"
	exit 1
fi
