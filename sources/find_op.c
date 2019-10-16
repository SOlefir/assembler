/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:12:08 by solefir           #+#    #+#             */
/*   Updated: 2019/10/16 21:58:44 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_op 	*find_op(char *str)
{
 	char	c;
 	int		op_len;
 	int		i;

	i = -1;
	while (++i < 16)
	{
		op_len = ft_strlen(g_op_tab[i].name_op);
		c = str[op_len];
		str[op_len] = 0;
		if (!ft_strcmp(str, g_op_tab[i].name_op))
		{
			str[op_len] = c;
			return (&g_op_tab[i]);
		}
		str[op_len] = c;
	}
	return (NULL);
}
