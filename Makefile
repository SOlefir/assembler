# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solefir <solefir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 21:25:16 by dquitzon          #+#    #+#              #
#    Updated: 2019/09/28 16:45:21 by solefir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

CC = gcc

DIR = ./sources/
HEADER = ./includes/asm.h ./includes/op.h #./includes/libft.h
LIB		:=	./libft.a

SOURCES	:=	main.c \
			get_name_comment.c \
			op.c \
			inits.c \
			definition.c \
			errors.c \
			extract_from_quotes.c \
			skip_whitespace.c

SOURCES	:=	$(addprefix $(DIR), $(SOURCES))

OBJ		:=	$(SOURCES:%.c=%.o)

CFLAGS	:=	$(addprefix -W, all extra error) \
			$(addprefix -I, $(HEADER))

all: $(NAME)

$(NAME): $(OBJ)
	${MAKE} -C ./libft/ all
	$(CC) $(OBJ) $(LIB) -o $@

clean:
	${MAKE} -C ./libft/ $@
	rm -f $(OBJ)

fclean: clean
	${MAKE} -C ./libft/ $@
	rm -f $(NAME)

re: fclean all
	${MAKE} -C ./libft/ $@
