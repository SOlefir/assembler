/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:00:13 by solefir           #+#    #+#             */
/*   Updated: 2019/10/07 00:56:08 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_code			*init_code(int len_code)
{
	t_code	*code;

	code = (t_code*)ft_memalloc(sizeof(t_code));
	code->size = len_code;
	code = (char*)ft_memalloc(len_code);
	code->next = NULL;
}

t_header		*init_header(void)
{
	t_header	*header;

	header = (t_header*)ft_memalloc(sizeof(t_header));
	header->magic = COREWAR_EXEC_MAGIC;
	header->prog_size = 0;
	return (header);
}

// t_arg_lbl		*init_arg_lable(char *name)
// {
// 	t_arg_lbl	*arg_lbl;

// 	arg_lbl = (t_lable*)ft_memalloc(sizeof(t_lable))
// 	arg_lbl->name = NULL;
// 	arg_lbl->where = NULL;
//	arg_lbl->code = NULL;
// 	arg_lbl->label = NULL;
// 	arg_lbl->next = NULL;
// 	return (arg_lbl);
//}

t_lbl		*init_label(char *name)
{
	t_lbl	*label;

	label = (t_lbl*)ft_memalloc(sizeof(t_lbl));
	label->name = name;
	label->in_arg = NULL;
	label->next = NULL;
	return (label);
}

t_holder		*init_holder(void)
{
	t_holder	*holder;

	holder = (t_holder*)ft_memalloc(sizeof(t_holder));
	holder->header = init_header();
	holder->bytes_count = 0;
	holder->arg_lbl = NULL;
	holder->labels = NULL;
	holder->binary = NULL;
	return (holder);
}
