/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:00:13 by solefir           #+#    #+#             */
/*   Updated: 2019/09/29 16:35:06 by solefir          ###   ########.fr       */
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

// t_arg_lbl		*init_arg_lable(void)
// {
// 	t_arg_lbl	*arg_lbl;

// 	arg_lbl = (t_lable*)ft_memalloc(sizeof(t_lable))
// 	arg_lbl->size = 0;
// 	arg_lbl->bytes_in_code = 0;
// 	arg_lbl->name_lbl = NULL;
// 	arg_lbl->in_code = NULL;
// 	arg_lbl->type = NULL;
// 	arg_lbl->lables = NULL;
// 	arg_lbl->nexst = NULL;
// 	return (arg_lbl);
// }

// t_lable		*init_lables(void)
// {
// 	t_lable	*lables;

// 	lables = (t_lable*)ft_memalloc(sizeof(t_lable))
// 	lables->dir = 0;
// 	lables->indir = 0;
// 	lables->in_arg = NULL;
// 	lables->next = NULL;
// 	return (lables);
// }

t_holder		*init_holder(void)
{
	t_holder	*holder;

	holder = (t_holder*)ft_memalloc(sizeof(t_holder));
	holder->header = init_header();
	holder->arg_lbl = NULL;
	holder->lables = NULL;
	holder->binary = NULL;
	return (holder);
}
