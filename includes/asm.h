/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:53:09 by solefir           #+#    #+#             */
/*   Updated: 2019/09/27 21:44:08 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H 

#include "op.h"
#include "libft.h"
/*
**		TYPEDEF
*/

typedef unsigned int	uint;

typedef struct  s_lable			t_lable;
typedef struct  s_arg_lbl		t_arg_lbl;
typedef struct  s_holder		t_holder;
typedef struct  s_binary		t_binary;
typedef struct  s_op			t_op;

/*
**		GLOBALS
*/

extern int		g_str_n;
extern int		g_byte_n;

/*
**		SRTUCTURES
*/

struct			s_lable
{
	int 			dir;
	int 			indir;
	t_arg_lbl	 	*in_arg;
	t_lable			*next;
};

struct			s_arg_lbl
{
	char			*name_lbl;
	char			*type;// (dir/indir)
	char			*in_code;
	int				size;
	int				bytes_in_code;
	t_lable  		*lables;
	t_arg_lbl	 	*next;
};

struct 			s_binary
{
	char		*code;
	uint		size;
	t_binary	*next;
};

struct			s_holder
{
	t_lable		*lables;
	t_arg_lbl	*arg_lbl;
	t_header	*header;
	t_binary	*binary;
};

struct			s_op
{
	char	*name_op;
	uint	params;
	uint	types[3];
	uint	index;
	uint	cyexec;
	char	*comment;
	_Bool	typeflag;
	_Bool	halfdir;
};


t_holder		*init_holder(void);
t_header		*init_header(void);
t_lable			*init_lables(void);
t_arg_lbl		*init_arg_lable(void);

_Bool			is_lable(char *str);
_Bool			is_instruction(char *str);
_Bool			is_name(char *str);
_Bool			is_comment(char *str);

char			*extract_from_quotes(int fd, char quote, char **str);

void			get_name_comment(int fd, t_header **header);
void			make_binary_code(t_holder **holder);
char			*make_name(char	*file_name);
void			insert_lables(t_holder **holder);

void			error_exit(char *massage, int byte);
char			*extract_from_quots(int fd, char quote, char **str);

_Bool			is_unnecessary(char **line, int i);
int				skip_whitespaces(char *str);
// void			check_nc(char *str, char f);
// t_header		*save_nc(int fd);
// char			**make_binary(char **line);

#endif
