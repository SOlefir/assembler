/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:53:09 by solefir           #+#    #+#             */
/*   Updated: 2019/10/15 00:33:41 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H 

#include "op.h"
#include "../libft/libft.h"
#include <fcntl.h>
/*
**		TYPEDEF
*/

typedef unsigned int	uint;

typedef struct s_label			t_label;
typedef struct s_arg_lbl		t_arg_lbl;
typedef struct s_holder			t_holder;
typedef struct s_binary			t_binary;
typedef struct s_args			t_args;
typedef struct s_op				t_op;

/*
**		GLOBALS
*/

extern int		g_str_n;
extern int		g_byte_n;

/*
**		STRUCTURES
*/

struct			t_lbl
{
	char			*name;
	int				value;
	int				byte_in_code;
	t_arg_lbl		*in_arg;
	t_label			*next;
};

struct			t_arg_lbl
{
	char			*name;
	char			*where;
	t_code			*code;
	t_label			*labels;
	t_arg_lbl		*next;
};

struct			t_args
{
	int		types;
	int		count_args;
	int		size_arg;
	int		*args;
	char	*label;

};

struct			t_code //возможно стоит заменить на либовские листы 
{
	char	*code;
	int		size;
	t_code	*next;
};

struct			t_holder
{
	int			bytes_count;
	t_lbl		*labels;
	t_arg_lbl	*arg_lbl;
	t_header	*header;
	t_code		*code;
};

struct			t_op
{
	char	*name_op;
	int		agr;
	int		arg_types[3];
	int		code_op;
	int		cyecles;
	char	*comment;
	_Bool	octet;
	_Bool	lbl_size;
};

t_holder		*init_holder(void);
t_header		*init_header(void);
t_label			*init_labels(void);
t_arg_lbl		*init_arg_label(void);

_Bool			is_label(char *str);
_Bool			is_(char *cmd, char *str);
_Bool			is_unnecessary(char **line, int i);

t_op 			*find_op(char *str);
char			*extract_from_quotes(int fd, char quote, char **str);

void			get_name_comment(int fd, t_header **header);
void			make_binary_code(t_holder **holder);
char			*make_name(char	*file_name);
void			insert_labels(t_holder **holder);

void			error_exit(char *massage, int byte);


int				skip_whitespaces(char *str);

// void			check_nc(char *str, char f);
// t_header		*save_nc(int fd);
// char			**make_binary(char **line);

#endif
