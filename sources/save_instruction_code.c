/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_instruction_code.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:18:01 by solefir           #+#    #+#             */
/*   Updated: 2019/10/18 21:26:53 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	free_args(t_args **arguments)
{
	if (*arguments == NULL)
		return ;
	free(*arguments);
	*arguments = NULL;
}

void		save_instruction_code(char *line, t_holder *holder, t_op *op)
{
	t_args		*arguments;
	t_instruct	*encoded;

	arguments = parse_code(line, op);
	encoded = encode_instruct(arguments);
	if (holder->code == NULL)
		holder->code = encoded;
	else 
	{
		holder->code->prev->next = encoded;
		encoded->prev = holder->code->prev;
		holder->code->prev = encoded;
	}
	encoded->pos_now = holder->bytes_count; 
	holder->bytes_count += encoded->size;
	free_args(&arguments);
}
