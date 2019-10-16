/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 15:13:07 by solefir           #+#    #+#             */
/*   Updated: 2019/10/16 15:22:01 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_lbl	*find_label(char *name, t_lbl *labels)
{
	while (labels != NULL && !ft_strcmp(labels->name, name))
		labels = labels->next;
	return (labels);
}

t_lbl	*add_label(t_lbl **labels, char *name_label)
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

void	save_label(char *name, char *in_code, int value, t_lbl **labels)
{
	t_lbl	*lbl;

	lbl = NULL;
	if (!(lbl = find_label(name, *labels)))
		lbl = add_label(labels, name);
	lbl->value = value ? value : lbl->value;
	lbl->in_code = in_code;
}
