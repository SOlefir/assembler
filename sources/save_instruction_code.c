/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_instruction_code.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:18:01 by solefir           #+#    #+#             */
/*   Updated: 2019/10/15 20:47:03 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	free_args(t_arg **arguments)
{
	if (*arguments == NULL)
		return ();
	if ((*arguments)->args != NULL)
	{
		free((*arguments)->args);
		(*arguments)->args = NULL;
	}
	if ((*arguments)->label != NULL)
	{
		free((*arguments)->label);
		(*arguments)->label = NULL;
	}
	free(*arguments);
	*arguments = NULL;
}

void		save_instruction_code(char *line, t_holder *holder, t_op *op)
{
	t_args	*arguments;

	arguments = parse_code(line, op,);
	save_label(holder);
	holder->code = encode_instruction(arguments, op, holder);
	holder->bytes_count += holder->size;
	free_args(arguments);
}
