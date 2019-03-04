#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rorousse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 03:14:08 by rorousse          #+#    #+#              #
#    Updated: 2016/08/04 20:10:27 by rorousse         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = testalloc
HEADER = malloc.h
SRC_PATH=./sources/
OBJ_PATH=./objs/
SRC = basic_test.c	\
		
OBJNAME= $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJNAME))
FLAGS = -Wall -Wextra -O0 -g -Wmissing-prototypes -Werror 

all: create_obj $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) ../malloc.so

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
	gcc $(FLAGS) -I headers/ -I ../headers -c $< -o $@

create_obj :
	mkdir -p $(OBJ_PATH)

clean:
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean  all
