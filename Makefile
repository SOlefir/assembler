# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solefir <solefir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 21:25:16 by dquitzon          #+#    #+#              #
#    Updated: 2019/09/27 21:49:43 by solefir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

DIR = ./sources/
HEADER = ./includes/asm.h ./includes/op.h #./includes/libft.h
LIB = ./libft.a

SOURCES = $(DIR)main.c $(DIR)get_name_comment.c $(DIR)op.c\
		$(DIR)inits.c $(DIR)definition.c $(DIR)errors.c\
		$(DIR)extract_from_quotes.c $(DIR)skip_whitespace.c\

OBJ = $(SOURCES:%.c=%.o)

FLAGS = #-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -c $(SOURCES) -I $(HEADER)
	gcc $(OBJ) $(LIB) -o $@

clean:
	rm -f $(OBJ)
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
