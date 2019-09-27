# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solefir <solefir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 21:25:16 by dquitzon          #+#    #+#              #
#    Updated: 2019/08/08 19:43:24 by solefir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCES = ./ft_bzero.c ./ft_memdel.c ./ft_strclr.c\
    ./ft_strdel.c ./ft_striter.c ./ft_striteri.c\
    ./ft_putchar.c ./ft_putchar_fd.c ./ft_putendl.c\
    ./ft_putendl_fd.c ./ft_putnbr.c ./ft_putnbr_fd.c\
    ./ft_putstr.c ./ft_putstr_fd.c ./ft_memalloc.c\
    ./ft_memcpy.c ./ft_memccpy.c ./ft_memchr.c\
    ./ft_memmove.c ./ft_memset.c ./ft_atoi.c\
    ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c\
    ./ft_isdigit.c ./ft_isprint.c ./ft_memcmp.c\
    ./ft_strcmp.c ./ft_strequ.c ./ft_strnequ.c\
    ./ft_strncmp.c ./ft_tolower.c ./ft_toupper.c\
    ./ft_itoa.c ./ft_strcat.c ./ft_strncat.c\
    ./ft_strnew.c ./ft_strchr.c ./ft_strrchr.c\
    ./ft_strcpy.c ./ft_strmap.c ./ft_strmapi.c\
    ./ft_strncpy.c ./ft_strdup.c ./ft_strjoin.c\
    ./ft_strstr.c ./ft_strnstr.c ./ft_strsub.c\
    ./ft_strtrim.c ./ft_strsplit.c ./ft_strlcat.c\
    ./ft_strlen.c ./ft_lstnew.c ./ft_lstmap.c\
    ./ft_lstdelone.c ./ft_lstdel.c ./ft_lstadd.c\
    ./ft_lstiter.c ./ft_masmemdel.c ./ft_lstdelcontent.c\
	./ft_iswhitespace.c ./get_next_line.c\
    \
    ./ft_printf.c ./parse_arg.c\
    ./print_buf.c ./flags.c\
	./specifier.c ./type_c.c\
    ./type_s.c\
    ./type_di.c ./type_u.c\
    ./type_x.c ./type_p.c\
    ./type_o.c ./add_in_buf.c\
	./width__precision.c ./len_nbr.c\
    ./nbr.c\

OBJ = $(SOURCES:%.c=%.o)
FLAGS = -Wall -Wextra -Werror #-fsanitize="address" -g -fno-omit-frame-pointer
HEADER = ./libft.h

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SOURCES) -I$(HEADER)
	ar rc $(NAME) $(OBJ) 
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
