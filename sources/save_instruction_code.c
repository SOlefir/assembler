/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_instruction_code.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:18:01 by solefir           #+#    #+#             */
/*   Updated: 2019/09/30 00:27:43 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	add_lbl(t_label **label, char name_label)
{
	if (*label == NULL)
	{
		holder->labels = init_labels(NULL);
		holder->labels->next = init_labels(label);		
	}
	else
		holder->labels->next = init_labels(label);
}

void	save_instruction_code(char *instruct, t_holder **holder, char *label)
{
	int	leng_code;

	if (label != NULL)
		add_lbl(&(holder->label), label);
	leng_code = check_instruction(instruct);// for Martin
	(*holder)->code = encode_instruct(instruct, leng_code);
}

// 1. если есть метка, то сохранить ее.
// 2. проверить валидность инструкции и какие аргументы. получить размер кода
// 3. перевести инстр. в байт код, сохранить адрес метки, если есть.

// функция которая смотрит корректная ли команда и какие ей передают аргументы. 
// и посчитывает ск байт нужно будет для кода этой инструкции.
// Если ошибка - выходит. если все ок - возвращает число байт для кода