/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 23:35:22 by solefir           #+#    #+#             */
/*   Updated: 2019/10/21 14:42:02 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdio.h>

unsigned short	encode_int(char *str, int value, int code_size)
{
	int		i;
	char	*by_byte_iterator;

	i = 0;
	by_byte_iterator = (char *)(&value);
	by_byte_iterator += (code_size - 1);
	while (i < code_size)
		str[i++] = *by_byte_iterator--;
	return (i);
}

void			encode(t_instruct *data, int value, char type, _Bool small)
{
	int		code_size;

	if (type == REG_CODE)
		code_size = 1;
	if (type == IND_CODE)
		code_size = 2;
	if (type == DIR_CODE)
		code_size = (small) ? 2 : 4;
	data->size += encode_int(data->str + data->size, value, code_size);
}

t_instruct		*encode_instruct(t_args *args)
{
	t_instruct	*data;
	t_op		now;
	int			i;

	now = g_op_tab[args->op_code];
	data = (t_instruct *)ft_memalloc(sizeof(t_instruct));
	data->label_places[0] = NULL;
	data->str = ft_strnew(now.count_args * sizeof(int) + ((now.octet) ? 2 : 1));
	data->size = (now.octet) ? 2 : 1;
	data->next = NULL;
	data->prev = data;
	data->str[0] = args->op_code + 1;
	data->str[1] = (now.octet) ? args->coding_byte : 0;
	i = -1;
	while (++i < now.count_args)
	{
		if (args->labels[i])
			add_label(data, args->labels[i], args->arg_types[i], now.lbl_size);
		else
			encode(data, args->args[i], args->arg_types[i], now.lbl_size);
	}
	return (data);
}
