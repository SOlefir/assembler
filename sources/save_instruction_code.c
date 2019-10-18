/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_instruction_code.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:18:01 by solefir           #+#    #+#             */
/*   Updated: 2019/10/17 20:25:25 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	free_args(t_args **arguments)
{
	if (*arguments == NULL)
		return ;
	// if ((*arguments)->args != NULL)
	// {
	// 	free((*arguments)->args);
	// 	(*arguments)->args = NULL;
	// }
	// if ((*arguments)->label != NULL)
	// {
	// 	free((*arguments)->label);
	// 	(*arguments)->label = NULL;
	// }
	free(*arguments);
	*arguments = NULL;
}

void		save_instruction_code(char *line, t_holder *holder, t_op *op)
{
	t_args		*arguments;
	t_instruct	*encoded;

	arguments = parse_code(line, op);
	// if (arguments->label) это должно быть в энкод инстр
	// 	save_label(arguments->label, NULL, -1, );
	// printf("zaparseno\n");
	// printf("\n\n\n");
	// printf("START ENCODING!!!\n");
	// system("leaks asm");
	encoded = encode_instruct(arguments);
	// printf("instruct saved\n");
	// system("leaks asm");
	// printf("END ENCODING!!!\n");
	// system("leaks asm");
	// printf("\n\n\n");
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
