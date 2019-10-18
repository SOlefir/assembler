/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:12:08 by solefir           #+#    #+#             */
/*   Updated: 2019/10/18 20:22:24 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_op 	*find_op(char *str)
{
 	char	c;
 	int		j;
 	int		i;

	i = 16;
	j = 0;
	while (!ft_iswhitespace(str[j]) && str[j] != '\0')
		j++;
	while (--i >= 0)
	{
		c = str[j];
		str[j] = 0;
		if (!ft_strcmp(str, g_op_tab[i].name_op))
		{
			str[j] = c;
			return (&g_op_tab[i]);
		}
		str[j] = c;
	}
	return (NULL);
}
