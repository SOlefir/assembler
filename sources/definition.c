/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definition.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:28:48 by solefir           #+#    #+#             */
/*   Updated: 2019/09/17 18:42:50 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

_Bool	is_instruction(char *str)
{
	int i;

	i = -1;
	while (++i < 17) 
		if (ft_strcmp(g_op_tab[i++]->name_op, str) != 0)
			return (1);
	return (0);
}

_Bool	is_name(char *str)
{
	int 	i;
	char	*command;

	command = NAME_CMD_STRING;
	i = ft_strlen(command);
	while (--i >= 0)
		if (str[i] != command[i])
			return (0);
	return (1);
}

_Bool	is_comment(char *str)
{
	int 	i;
	char	*command;

	command = COMMENT_CMD_STRING;
	i = ft_strlen(command);
	while (--i >= 0)
		if (str[i] != command[i])
			return (0);
	return (1);
}
