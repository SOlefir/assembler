# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solefir <solefir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 21:25:16 by dquitzon          #+#    #+#              #
#    Updated: 2019/09/16 14:51:11 by solefir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

DIR = ./sources/
HEADER = includes/asm.h includes/op.h #includes/libft.h
LIB = $(DIR)libft.a

SOURCES = $(DIR)main.c $(DIR)validation.c $(DIR)get_name_comment.c\
		$(DIR)make_binary.c $(DIR)definition.c $(DIR)op.c\

OBJ = $(SOURCES:%.c=%.o)

FLAGS = #-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(DIR)gcc $(FLAGS) -c $(SOURCES) -I $(HEADER)
	$(DIR)gcc $(OBJ) $(LIB) -o $@
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
		