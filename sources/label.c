/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 15:13:07 by solefir           #+#    #+#             */
/*   Updated: 2019/10/15 20:43:32 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_lbl	*find_label(char *name, t_lbl *labels)
{
	while (labels != NULL && !t_strcmp(labels->name, name))
		labels = labels->next;
	return (labels);
}

t_lbl	*add_label(t_label **labels, char name_label)
{
	t_lbl	*temp;

	if (*label == NULL)
	{
		(*labels) = init_labels(NULL);
		(*labels)->next = init_labels(label);
		return ((*labels)->next);
	}
	temp = *labels;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = init_labels(label);
	return (temp->next);
}

void	save_label(char *name, char *in_code, int value, t_lbl **labels)
{
	t_lbl	*lbl;

	lbl = NULL;
	if (!(lbl = find_label(name, *labels)))
		lbl = add_label(labels, name);
	lbl->value = value ? value : lbl->value;
	lbl->in_code = in_code;
}
