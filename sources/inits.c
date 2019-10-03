/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:00:13 by solefir           #+#    #+#             */
/*   Updated: 2019/10/03 13:44:17 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

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
// 	arg_lbl->in_code = NULL;
// 	arg_lbl->type = NULL;
// 	arg_lbl->label = NULL;
// 	arg_lbl->nexst = NULL;
// 	return (arg_lbl);
//}

// t_lable		*init_label(char *name)
// {
// 	t_lable	*label;

// 	label = (t_lable*)ft_memalloc(sizeof(t_label));
// 	label->name = name;
// 	label->in_arg = NULL;
// 	label->next = NULL;
// 	return (label);
// }

t_holder		*init_holder(void)
{
	t_holder	*holder;

	holder = (t_holder*)ft_memalloc(sizeof(t_holder));
	holder->header = init_header();
	holder->arg_lbl = NULL;
	holder->label = NULL;
	holder->binary = NULL;
	return (holder);
}
