/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:53:09 by solefir           #+#    #+#             */
/*   Updated: 2019/10/16 19:22:30 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H 

#include "op.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include "stdio.h"//

/*
**		TYPEDEF
*/


typedef struct s_op				t_op;
typedef struct s_args			t_args;
typedef struct s_code			t_code;
typedef struct s_lbl			t_lbl;
typedef struct s_holder			t_holder;

/*
** GLOBAL VAR THAT USED IN FUNCT EXIT_ERRORS 
*/


/*
**		STRUCTURES
*/

typedef struct			s_op
{
	char	*name_op;
	int		arg;
	int		arg_types[3];
	int		code_op;
	int		cyecles;
	char	*comment;
	_Bool	octet;
	_Bool	lbl_size;
}						t_op;

typedef struct			s_lbl
{
	char			*name;
	int				value;
	char			*in_code;
	t_lbl			*next;
}						t_lbl;

typedef struct			s_code //возможно стоит заменить на либовские листы 
{
	char	*code;
	int		size;
	t_code	*next;
}						t_code;

typedef struct			s_holder
{
	int			bytes_count;
	t_lbl		*labels;
	t_header	*header;
	t_code		*code;
}						t_holder;


typedef struct			s_args
{
	unsigned char	coding_byte;
	unsigned char	op_code;
	unsigned char	arg_types[3];
	int				args[3];
	char			*labels[3];
}						t_args;

typedef struct			s_args
{
	int		types;
	int		count_args;
	int		size_arg;
	int		*args;
	char	*label;
}						t_args;

extern int		g_str_n;
extern t_op		g_op_tab[17];


/**  main  **/

void			get_name_comment(int fd, t_header *header);
void			get_instruction(int fd_arg, t_holder *holder);
t_args			*parse_code(char *instr, t_op *op);
void			save_instruction_code(char *line, t_holder *holder, t_op *op);
void			insert_labels(t_holder **holder);
void			error_exit(char *massage, int byte);

/**  inits  **/

t_holder		*init_holder(void);
t_header		*init_header(void);
t_lbl			*init_labels(char *name);
t_args			*init_args(int count_args);
t_code			*init_code(int len_code);

/**  definition  **/

char			*is_label(char *str);
_Bool			is_(char *cmd, char *str);
_Bool			is_unnecessary(char **line, int i);

/**  label  **/

void			save_label(char *name, char *in_code,
							int value, t_lbl **labels);
t_lbl			*add_label(t_lbl **labels, char *name_label);
t_lbl			*find_label(char *name, t_lbl *labels);

/**  other  **/

int				atoi_for_args(char **str, char end);
int				skip_whitespaces(char *str);
t_op 			*find_op(char *str);
char			*extract_from_quotes(int fd, char quote, char **str);
char			*make_name(char	*file_name);


#endif
