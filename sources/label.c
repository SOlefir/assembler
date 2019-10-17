/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 15:13:07 by solefir           #+#    #+#             */
/*   Updated: 2019/10/17 20:30:38 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

// t_lbl	*find_label(char *name, t_lbl *labels)
// {
// 	while (labels != NULL && !ft_strcmp(labels->name, name))
// 		labels = labels->next;
// 	return (labels);
// }

int			label_value(char *label_name, t_lbl *labels)
{
	while (labels)
	{
		if !(strcmp(labels->name, label_name))
			return labels->value;
		labels = labels->next;
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

t_lbl	*save_label(t_lbl **labels, char *name_label)
{
	t_lbl	*temp;

	if (*labels == NULL)
	{
		(*labels) = init_labels(NULL);
		(*labels)->next = init_labels(name_label);
		return ((*labels)->next);
	}
	temp = *labels;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = init_labels(name_label);
	return (temp->next);
}

// void	save_label(char *name, char *in_code, int value, t_lbl **labels)
// {
// 	t_lbl	*lbl;

// 	lbl = NULL;
// 	if (!(lbl = find_label(name, *labels)))
// 		lbl = add_label(labels, name);
// 	lbl->value = value ? value : lbl->value;
// 	lbl->in_code = in_code;
// }
