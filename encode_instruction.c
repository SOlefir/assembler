/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 23:35:22 by solefir           #+#    #+#             */
/*   Updated: 2019/10/07 00:48:12 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

typedef struct	s_instruct
{
	unsigned short	size;
	char			*str;
	size_t			start_pos;
	unsigned short	label_sizes[3];
	char			*label_places[3];
	char			*label_names[3];
}				t_instruct;

void		add_label(t_instruct *data, char *label, char type, _Bool small)
{
	int		i;

	i = 0;
	while (data->label_places[i])
		i++;
	if (type == IND_CODE)
		data->label_sizes[i] = 2
	else if (type == DIR_CODE)
		data->label_sizes[i] = (small) ? 2 : 4;
	data->label_names[i] = ft_strdup(label);
	data->label_places[i] = data->str + data->size;
	data->size += data->label_sizes[i];
	if ((i + 1) < 3)
		data->label_places[i + 1] = NULL;
}
unsigned short	encode_int(char *str, int value, int code_size)
{
	int		i;
	char	*by_byte_iterator;

	i = 0;
	by_byte_iterator = (char *)(&value);
	by_byte_iterator += (code_size - 1);
	while (i < code_size)
		str[i++] = *(by_byte_iterator--);
	return i;
}

void			encode(t_instruct *data, int value, char type, _Bool small)
{
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
	// i = -1;
	// by_byte_iterator = (char *)(&value);
	// by_byte_iterator += (code_size - 1);
	// while (++i < code_size)
	// 	data->str[data->size++] = *(by_byte_iterator--);
}

t_instruct	*encode_instruct(t_args *args, size_t bytes_now) 
{ 
	t_instruct	*data; 
	t_op		now; 
	char		i; 

	now = g_op_tab[args->op_code] 
	data = (t_instruct *)malloc(sizeof(t_instruct)); 
	data->label_places[0] = NULL;
	data->str = ft_strnew(now->arg * sizeof(int) + ((now->octet) ? 2 : 1)) 
	data->size = (now->octet) ? 2 : 1; 
	data->str[0] = args->op_code; 
	data->str[1] = (now->octet) ? args->coding_byte : 0; 
	i = -1; 
	while (++i < now->arg) 
	{
		if (args->labels[i]) 
			add_label(data, args->labels[i], args->arg_types[i], now->lbl_size); 
		else 
			encode(data, args->args[i], args->arg_types[i], now->lbl_size); 
	}
	return data; 
} 

int			label_value(char *label_name, t_label_list *labels_head)
{
	while (labels_head)
	{
		if !(strcmp(labels_head->name, label_name))
			return labels_head->value;
		labels_head = labels_head->next;
	}
	return -1;
}

void		label_input(t_instruct_list *head, t_label_list *lhead)
{
	t_instruct	inow;
	int			val;
	char		i;

	while (head)
	{
		inow = head->instruct;
		i = -1;
		while (++i < 3 && inow->label_names[i])
		{
			val = label_value(inow->label_names[i], lhead);
			encode_int(inow->label_places[i], val, inow->label_sizes[i]);
		}
	}
}