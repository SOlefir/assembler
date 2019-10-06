/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:28:48 by solefir           #+#    #+#             */
/*   Updated: 2019/10/06 15:08:13 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static _Bool	is_lblchar(char c)
{
	return (((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')
		|| c == '_') ? 1 : 0);
}

int			is_label(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		while (is_lblchar(str[i]))
			i++;
		if (str[i++] == 'LABEL_CHAR')// && i += skip_whitespaces(&str[i]) >= 0)
			return (i);
	}
	return (0);
}

_Bool			is_unnecessary(char **line, int i)
{
	if ((*line)[i] == '\0' || (*line)[i] == COMMENT_CHAR)
	{
		ft_strdel(line);
		return (1);
	}
	return (0);
}

_Bool			is_(char *cmd, char *str)
{
	int	len_cmd;
	int	i;

	i = -1;
	len_cmd = ft_strlen(cmd);
	while (++i < len_cmd)
		if (str[i] != cmd[i])
			return (0);
	return (1);
}
