/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definition.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:28:48 by solefir           #+#    #+#             */
/*   Updated: 2019/09/28 16:47:47 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

_Bool	is_lable(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		while (!ft_iswhitespace(str[i]))
			i++;
		while (ft_isalpha((int)str[i]))
			i++;
		if (str[i] == ':')
			return (1);
	}
	return (0);
}

// _Bool	is_instruction(char *str)
// {
// 	int i;

// 	i = -1;
// 	while (++i < 17) 
// 		if (ft_strcmp(g_op_tab[i].name_op, str) != 0)
// 			return (1);
// 	return (0);
// }

_Bool		is_unnecessary(char **line, int i)
{
	if ((*line)[i] == '\0' || (*line)[i] == COMMENT_CHAR)
	{
		ft_strdel(line);
		return (1);
	}
	return (0);
}

_Bool	is_(char *cmd, char *str)
{
	int 	i;

	i = 0;
	i = ft_strlen(cmd);
	while (--i)
		if (str[i] != cmd[i])
			return (0);
	return (1);
}

