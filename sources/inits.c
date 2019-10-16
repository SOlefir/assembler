/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:00:13 by solefir           #+#    #+#             */
/*   Updated: 2019/10/16 15:32:08 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_code			*init_code(int len_code)
{
	t_code	*code;

	code = (t_code*)ft_memalloc(sizeof(t_code));
	code->size = len_code;
	code = NULL;
	code->next = NULL;
	return (code);
}

t_header		*init_header(void)
{
	t_header	*header;

	header = (t_header*)ft_memalloc(sizeof(t_header));
	header->magic = COREWAR_EXEC_MAGIC;
	header->prog_size = 0;
	return (header);
}

t_args		*init_args(int count_args)
{
	t_args	*arg;
	arg = (t_args*)ft_memalloc(sizeof(t_args));
	arg->count_args = count_args;
	arg->args = (int*)ft_memalloc(sizeof(int) * count_args);
	arg->label = NULL;
	return (arg);
}

t_lbl		*init_labels(char *name)
{
	t_lbl	*label;

	label = (t_lbl*)ft_memalloc(sizeof(t_lbl));
	label->name = name;
	label->in_code = NULL;
	label->next = NULL;
	return (label);
}

t_holder		*init_holder(void)
{
	t_holder	*holder;

	holder = (t_holder*)ft_memalloc(sizeof(t_holder));
	holder->header = init_header();
	holder->labels = NULL;
	holder->code = NULL;
	return (holder);
}
