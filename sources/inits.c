/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:00:13 by solefir           #+#    #+#             */
/*   Updated: 2019/10/20 16:59:05 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			init_null(char **line, char **comment, char **name, int *end)
{
	*end = 0;
	*line = NULL;
	*comment = NULL;
	*name = NULL;
}

t_header		*init_header(void)
{
	t_header	*header;

	header = (t_header*)ft_memalloc(sizeof(t_header));
	header->magic = COREWAR_EXEC_MAGIC;
	header->prog_size = 0;
	return (header);
}

t_args			*init_args(unsigned char op_code)
{
	t_args	*arg;

	arg = (t_args*)ft_memalloc(sizeof(t_args));
	arg->op_code = op_code;
	return (arg);
}

t_lbl			*init_labels(char *name, int value)
{
	t_lbl	*label;

	label = (t_lbl*)ft_memalloc(sizeof(t_lbl));
	label->name = name;
	label->value = value;
	return (label);
}

t_holder		*init_holder(void)
{
	t_holder	*holder;

	holder = (t_holder*)ft_memalloc(sizeof(t_holder));
	holder->header = init_header();
	holder->labels = NULL;
	holder->code = NULL;
	holder->bytes_count = 0;
	return (holder);
}
