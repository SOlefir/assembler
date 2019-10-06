/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_instruction_code.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:18:01 by solefir           #+#    #+#             */
/*   Updated: 2019/10/07 00:47:55 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	add_value_to_label(t_lbl **labels, int where_instruct)
{
	t_lbl	*temp;

	temp = *labels;
	while ((*labels) != NULL)
	{
		if ((*labels)->value == 0)
			(*labels)->value = where_instruct;
		(*labels) = (*labels)->next;
	}
	*labels = temp;
}

void		save_instruction_code(char *instruct, t_holder *holder)
{
	int len_code;

	len_code = parse_code(instruct); // подсчет байтов + валидация.
	if (holder->labels != NULL)
		add_value_to_label(&(holder->labels), holder->bytes_count);	
	holder->code = init_code(len_code);
	encode_instruction(instruct, &(holder->code));
	holder->bytes_count += len_code;
}

// 1. если есть метка, то записать ее значение (в цикле. если в метке не записано значение,
			//		то присваивать эту инструкцию) <<========= add_value_to_label;
// 2. проверить валидность инструкции и какие аргументы. получить размер кода
// 3. перевести инстр. в байт код, сохранить адрес метки, если есть.

// функция которая смотрит корректная ли команда и какие ей передают аргументы. 
// и посчитывает ск байт нужно будет для кода этой инструкции.