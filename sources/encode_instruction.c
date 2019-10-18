/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 23:35:22 by solefir           #+#    #+#             */
/*   Updated: 2019/10/17 20:23:28 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"


// void		add_label(t_instruct *data, char *label, char type, _Bool small)
// {
// 	int		i;

// 	i = 0;
// 	while (data->label_places[i])
// 		i++;
// 	if (type == IND_CODE)
// 		data->label_sizes[i] = 2
// 	else if (type == DIR_CODE)
// 		data->label_sizes[i] = (small) ? 2 : 4;
// 	data->label_names[i] = ft_strdup(label);
// 	data->label_places[i] = data->str + data->size;
// 	data->size += data->label_sizes[i];
// 	if ((i + 1) < 3)
// 		data->label_places[i + 1] = NULL;
// }

unsigned short	encode_int(char *str, int value, int code_size)
{
	int		i;
	char	*by_byte_iterator;

	i = 0;
	by_byte_iterator = (char *)(&value);
	by_byte_iterator += (code_size - 1);
	while (i < code_size)
		str[i++] = *by_byte_iterator--;
	return i;
}

void			encode(t_instruct *data, int value, char type, _Bool small)
{
	char	*now;
	int		to;
	int		i;

	i = -1;
	if (type == REG_CODE)
		to = 0;
	if (type == IND_CODE)
		to = 1;
	if (type == DIR_CODE)
		to = (small) ? 1 : 3;
	now = (char *)(&value);
	now += to;
	while (++i < (to + 1))
		data->str[(data->size)++] = *now--;
	return;

	// int		i;
	int		code_size;
	// char	*by_byte_iterator;

	if (type == REG_CODE)
		code_size = 1;
	if (type == IND_CODE)
		code_size = 2;
	if (type == DIR_CODE)
		code_size = (small) ? 2 : 4;
	data->size += encode_int(data->str, value, code_size);
	printf("CS(%d)(%d)(", code_size, value);
	for (int i = 0; i < code_size; i++)
		printf("%x ", (int)data->str[i]);
	printf(") ");

	// i = -1;
	// by_byte_iterator = (char *)(&value);
	// by_byte_iterator += (code_size - 1);
	// while (++i < code_size)
	// 	data->str[data->size++] = *(by_byte_iterator--);
}

t_instruct	*encode_instruct(t_args *args) 
{ 
	t_instruct	*data; 
	t_op		now; 
	int			i; 

	now = g_op_tab[args->op_code];
	data = (t_instruct *)ft_memalloc(sizeof(t_instruct)); 
	// data->label_names = (char **)ft_memalloc(sizeof(char *) * 3);
	data->label_places[0] = NULL;
	data->str = ft_strnew(now.count_args * sizeof(int) + ((now.octet) ? 2 : 1)); 
	data->size = (now.octet) ? 2 : 1; 
	if (now.octet)
		printf("have octet\n");
	data->next = NULL;
	data->prev = data;
	data->str[0] = args->op_code + 1; 
	printf("Op code: %d\n", args->op_code);
	data->str[1] = (now.octet) ? args->coding_byte : 0; 
	printf("CB: %d\n", args->coding_byte);
	i = -1; 
	printf("%s : ", now.name_op);
	while (++i < now.count_args) 
	{
		// printf("ok1\n");
		if (args->labels[i]) 
		{
			printf("L|%s|", args->labels[i]);
			// printf("ok2\n");
			add_label(data, args->labels[i], args->arg_types[i], now.lbl_size); 
		}
		else 
		{
			printf("O|%d %d|", args->arg_types[i], args->args[i]);
			// printf("ok3\n");
			encode(data, args->args[i], args->arg_types[i], now.lbl_size); 
		}
	}
	return data; 
} 

// int			label_value(char *label_name, t_label_list *labels_head)
// {
// 	while (labels_head)
// 	{
// 		if !(strcmp(labels_head->name, label_name))
// 			return labels_head->value;
// 		labels_head = labels_head->next;
// 	}
// 	return -1;
// }

// void		label_input(t_instruct_list *head, t_label_list *lhead)
// {
// 	t_instruct	inow;
// 	int			val;
// 	char		i;

// 	while (head)
// 	{
// 		inow = head->instruct;
// 		i = -1;
// 		while (++i < 3 && inow->label_names[i])
// 		{
// 			val = label_value(inow->label_names[i], lhead);
// 			encode_int(inow->label_places[i], val, inow->label_sizes[i]);
// 		}
// 	}
// }