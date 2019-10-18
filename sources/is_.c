/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:28:48 by solefir           #+#    #+#             */
/*   Updated: 2019/10/16 17:07:03 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static _Bool	is_lblchar(char c)
{
	return (((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')
		|| c == '_') ? 1 : 0);
}

char			*is_label(char *str)
{
	int i;

	i = 0;
	// while (str[++i] != '\0')
	// {
	while (is_lblchar(str[i]))
		i++;
	if (str[i] == LABEL_CHAR)
		return (ft_strndup(str, i));
	// }
	return (NULL);
}

_Bool			is_unnecessary(char **line, int i)
{
	if ((*line)[i] == '\0' || (*line)[i] == COMMENT_CHAR ||
		(*line)[i] == ALT_COMMENT_CHAR)
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
