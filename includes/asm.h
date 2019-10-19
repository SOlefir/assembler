/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:53:09 by solefir           #+#    #+#             */
/*   Updated: 2019/10/19 16:55:37 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "../libft/libft.h"
# include <fcntl.h>

/*
**		DEFINE
*/

# define COR ".cor"
# define COR_SIZE 4

/*
**		TYPEDEF
*/

typedef struct s_op				t_op;
typedef struct s_args			t_args;
// typedef struct s_code			t_code;
typedef struct s_lbl			t_lbl;
typedef struct s_holder			t_holder;
typedef struct s_instruct		t_instruct;

/*
**		STRUCTURES
*/

struct			s_op
{
	char	*name_op;
	int		count_args;
	int		arg_types[3];
	int		code_op;
	int		cyecles;
	char	*comment;
	_Bool	octet;
	_Bool	lbl_size;
};

// struct			s_code
// {
// 	char			*code;
// 	int				size;
// 	t_code			*next;
// };

struct			s_lbl
{
	char			*name;
	int				value;
	t_lbl			*next;
};

struct			s_instruct
{
	unsigned short		size;
	char				*str;
	size_t				pos_now;
	unsigned short		label_sizes[3];
	char				*(label_places[3]);
	char				*(label_names[3]);
	t_instruct			*next;
	t_instruct			*prev;
};

struct			s_holder
{
	size_t		bytes_count;
	t_lbl		*labels;
	t_header	*header;
	t_instruct	*code;
};

struct			s_args
{
	unsigned char		op_code;
	unsigned char		coding_byte;
	unsigned char		arg_types[3];
	int					args[3];
	char				*labels[3];
};

/*
** 		GLOBAL VAR
*/

extern int		g_str_n;
extern t_op		g_op_tab[17];

/*
** 		GLOBAL VAR
*/

void			get_name_comment(int fd, t_header *header);
void			get_instruction(int fd, t_holder *holder);
t_args			*parse_code(char *instr, t_op *op);
void			save_instruction_code(char *line, t_holder *holder, t_op *op);
unsigned short	encode_int(char *str, int value, int code_size);
t_instruct		*encode_instruct(t_args *args);
void			insert_labels(t_holder **holder);
void			error_exit(char *massage, int byte);

/*
**	main
*/

t_holder		*init_holder(void);
t_header		*init_header(void);
t_lbl			*init_labels(char *name, int value);
t_args			*init_args(unsigned char op_code);
// t_code			*init_code(int len_code);

/*
**	is-file
*/

_Bool			is_lblchar(char c);
char			*is_label(char *str);
_Bool			is_(char *cmd, char *str);
_Bool			is_unnecessary(char **line, int i);

/*
**	labels
*/

char			*get_lbl_name(char **instr);
t_lbl			*save_label(t_lbl **labels, char *name_label, int value);
void			label_input(t_instruct *inow, t_lbl *lhead);
void			add_label(t_instruct *data, char *label, char type,
																_Bool small);
t_lbl			*find_label(char *name, t_lbl *labels);

/*
**	other
*/

int				atoi_for_args(char **str);
int				skip_whitespaces(char *str);
t_op			*find_op(char *str);
char			*extract_from_quotes(int fd, char quote, char **str);

/*
**	write
*/

char			*make_name(char *name_champ);
void			write_uints(int fd, unsigned int out, _Bool size);
void			write_in_file(char *prog_name, t_holder *holder);

#endif
