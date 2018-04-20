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

NAME = malloc.so
HEADER = malloc.h
SRC_PATH=./sources/
OBJ_PATH=./objs/
SRC = 	free.c			\
		malloc.c		\
		placement.c		\
		show.c			\
		field.c			\
		zones.c			\
		search.c		\
		realloc.c		\
		
LIBS = libft/libft.a
OBJNAME= $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJNAME))
FLAGS = -Wall -Wextra -O0 -g -Wmissing-prototypes -Werror -fPIC

all: create_obj $(NAME)

$(NAME): $(OBJ)
	gcc -shared -fPIC -o $(NAME) $(OBJ) $(LIBS)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
	gcc $(FLAGS) -I headers/ -I libft/ -c $< -o $@

create_obj :
	make -C libft/
	mkdir -p $(OBJ_PATH)

clean:
	make clean -C libft/
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	make fclean -C libft/
	/bin/rm -f $(NAME)

re:	fclean  all
