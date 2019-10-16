# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solefir <solefir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 21:25:16 by dquitzon          #+#    #+#              #
#    Updated: 2019/10/16 17:17:35 by solefir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

CC = gcc

DIR = ./sources/
HEADER = ./includes/asm.h ./includes/op.h #./includes/libft.h
LIB		:=	./libft/libft.a

SOURCES	:=	main.c \
			get_name_comment.c \
			op.c \
			errors.c \
			inits.c \
			get_instruction.c \
			is_.c \
			extract_from_quotes.c \
			skip_whitespace.c\
			parse_code.c\
			save_instruction_code.c\
			label.c\
			atoi_for_args.c\
			find_op.c\

SOURCES	:=	$(addprefix $(DIR), $(SOURCES))

OBJ		:=	$(SOURCES:%.c=%.o)

CFLAGS	:=	$(addprefix -W, all extra error) \
			$(addprefix -I, $(HEADER))\
			#-fsanitize="address" -g -fno-omit-frame-pointer

all: $(NAME)

$(NAME): $(OBJ)
	${MAKE} -C ./libft/ all
	$(CC) $(OBJ) $(LIB) $(CFLAGS) -o $@

clean:
	${MAKE} -C ./libft/ $@
	rm -f $(OBJ)

fclean: clean
	${MAKE} -C ./libft/ $@
	rm -f $(NAME)

re: fclean all
	${MAKE} -C ./libft/ $@
