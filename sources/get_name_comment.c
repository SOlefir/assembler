/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:40:11 by solefir           #+#    #+#             */
/*   Updated: 2019/10/03 16:36:20 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static _Bool	empty_nc(char *command)
{
	int	i;

	if (command == NULL)
		return (1);
	i = skip_whitespaces(command);
	if (command == NULL || command[i] == '\0')
		return (1);
	return (0);
}

static void		last_check_nc(char *name, char *comment)
{
	if ((is_(NAME_CMD_STRING, line) && name) ||
		is_(COMMENT_CMD_STRING, line) && comment)
		error_exit("повтор команды или мусор на этой строке", 0);
	if (name == NULL && comment == NULL)
		error_exit("неопределена команда", 0);	
	if (empty_nc(name))
		error_exit("There is no name.", 0);
	if (empty_nc(comment))
		error_exit("There is no comment.", 0);
	if (ft_strlen(comment) > COMMENT_LENGTH)
		error_exit("comment is biger than...", 0);
	if (ft_strlen(name) > PROG_NAME_LENGTH)
		error_exit("name is biger than...", 0);
}

static char		*get_quote(int fd, char *line, int size_cmd)
{
	int		i;
	char	*quot;
	char	*end_quot;
	char	*temp;

	end_quot = 0;
	quot = NULL;
	i = size_cmd;
	i += skip_whitespaces(&line[i]);
	if (line[i] == '"')
	{
		temp = ft_strdup(&line[++i]);
		quot = extract_from_quotes(fd, '"', &temp);
	}
	else
		error_exit("Have`n quotes", 0);//написать что имя заданно не корректно
	end_quot = ft_strchr(temp, '"');
	i = skip_whitespaces(end_quot) + 1;
	if (end_quot[i] != '\0' && end_quot[i] != COMMENT_CHAR)
		error_exit("garbadge after quotes", 0);
	ft_strdel(&temp);
	return (quot);
}

static void		save_in_heder(t_header **header, char *name, char *comment)
{
	int	i;

	i = 0;
	ft_printf("\nname: %s\ncomment: %s\n", name, comment);
	while (++i <= PROG_NAME_LENGTH + 1)
		if (name[i])
			(*header)->prog_name[i] = name[i];
		else
			(*header)->prog_name[i] = 0;
	i = 0;
	while (++i <= COMMENT_LENGTH + 1)
		if (comment[i])
			(*header)->comment[i] = comment[i];
		else
			(*header)->comment[i] = 0;
	ft_strdel(&name);
	ft_strdel(&comment);
}

void			get_name_comment(int fd, t_header **header)
{
	int		i;
	char	*line;
	char	*name;
	char	*comment;

	line = NULL;
	comment = NULL;
	name = NULL;
	ft_printf("\n_____________\n");
	while (get_next_line(fd, &line) && (i = skip_whitespaces(line)) >= 0)
	{
		g_str_n++;
		if (is_unnecessary(&line, i))
			continue ;
		if (is_(NAME_CMD_STRING, &line[i]) && !name)
			name = get_quote(fd, line, ft_strlen(NAME_CMD_STRING) + i);
		else if (is_(COMMENT_CMD_STRING, &line[i]) && !comment)
			comment = get_quote(fd, line, ft_strlen(COMMENT_CMD_STRING) + i);
		else if ((name && comment) || !name || !comment)
			break ;
	}
	last_check_nc(name, comment, &line[i]);
	save_in_heder(header, name, comment);
}
