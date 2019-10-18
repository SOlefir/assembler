/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 15:13:07 by solefir           #+#    #+#             */
/*   Updated: 2019/10/19 01:47:25 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		*get_lbl_name(char **instr)
{
	int len_lnl;
	int i;
	char *name;

	i = -1;
	len_lnl = 0;
	(*instr)++;
	while (is_lblchar((*instr)[len_lnl]))
		len_lnl++;
	name = (char*)ft_memalloc(len_lnl + 1);
	name[len_lnl] = '\0';
	while (++i < len_lnl)
	{
		name[i] = **instr;
		(*instr)++;
	}
	return (name);
}

int			label_value(char *label_name, t_lbl *labels)
{
	while (labels)
	{
		if (!(strcmp(labels->name, label_name)))
			return (labels->value);
		labels = labels->next;
	}
	return (-1);
}

void		label_input(t_instruct *inow, t_lbl *lhead)
{
	int			val;
	int			i;

	while (inow)
	{
		i = -1;
		while (++i < 3 && inow->label_places[i])
		{
			if ((val = label_value(inow->label_names[i], lhead)) != -1)
				error_exit("Unknown label in arguments", 0);
			val = val - (inow->pos_now + 1);
			encode_int(inow->label_places[i], val, inow->label_sizes[i]);
		}
		inow = inow->next;
	}
}

void		add_label(t_instruct *data, char *label, char type, _Bool small)
{
	int		i;

	i = 0;
	while (data->label_places[i])
		i++;
	if (type == IND_CODE)
		data->label_sizes[i] = 2;
	else if (type == DIR_CODE)
		data->label_sizes[i] = (small) ? 2 : 4;
	data->label_names[i] = label;
	data->label_places[i] = data->str + data->size;
	data->size += data->label_sizes[i];
	if ((i + 1) < 3)
		data->label_places[i + 1] = NULL;
}

t_lbl	*save_label(t_lbl **labels, char *name_label, int value)
{
	t_lbl	*temp;

	if (*labels == NULL)
	{
		*labels = init_labels(name_label, value);
		return (*labels);
	}
	temp = *labels;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = init_labels(name_label, value);
	return (temp->next);
}
