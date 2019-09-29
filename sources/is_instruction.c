/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:12:08 by solefir           #+#    #+#             */
/*   Updated: 2019/09/29 20:14:41 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"



_Bool	is_instruction(char *str)
{
	int i;

	i = -1;
	while (++i < 16)
		if (ft_strcmp(g_op_tab[i].name_op, str) != 0)
			return (1);
	return (0);
}
