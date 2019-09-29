/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 23:34:27 by solefir           #+#    #+#             */
/*   Updated: 2019/09/30 00:48:06 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		check_instruction(char *instruct)
{
	int		i;
	int		leng;
	t_op	*op;

	op = find_op(instruct);
	i = ft_strlen(op.name_op);
	while (instruct[i] != '\0')
	{
		if (op.)
	}
	return (op);
}
