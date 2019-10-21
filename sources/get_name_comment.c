/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:40:11 by solefir           #+#    #+#             */
/*   Updated: 2019/10/20 22:16:37 by solefir          ###   ########.fr       */
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

static void		last_check_nc(char *name, char *comment, int end)
{
	if (end)
		error_exit("Empty file", 0);
	if (empty_nc(name))
		ft_putendl("WARRNING: player name is not filled!");
	if (empty_nc(comment))
		ft_putendl("WARRNING: comment is not filled!");
	if (ft_strlen(comment) > COMMENT_LENGTH)
		error_exit("Player comment is longer than 2048 bytes!", 1);
	if (ft_strlen(name) > PROG_NAME_LENGTH)
		error_exit("Player name is longer than 128 bytes!", 1);
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
		error_exit("After name or comment commands there should be quotes!",
																			1);
	end_quot = ft_strchr(temp, '"') + 1;
	i = skip_whitespaces(end_quot);
	if (end_quot[i] != '\0' && end_quot[i] != COMMENT_CHAR
		&& end_quot[i] != ALT_COMMENT_CHAR)
		error_exit("Invalid character after quotes!", 1);
	ft_strdel(&temp);
	return (quot);
}

static void		save_in_heder(t_header *header, char *name, char *comment)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < PROG_NAME_LENGTH + 1)
		if (name[j] != '\0')
			header->prog_name[i] = name[j++];
		else
			header->prog_name[i] = 0;
	i = -1;
	j = 0;
	while (++i < COMMENT_LENGTH + 1)
		if (comment[j] != '\0')
			header->comment[i] = comment[j++];
		else
			header->comment[i] = 0;
	ft_strdel(&name);
	ft_strdel(&comment);
}

void			get_name_comment(int fd, t_header *header)
{
	int		i;
	int		end;
	char	*line;
	char	*name;
	char	*comment;

	init_null(&line, &comment, &name, &end);
	while ((get_next_line(fd, &line)) > 0 && (i = skip_whitespaces(line)) >= 0)
	{
		g_str_n++;
		if ((end = is_unnecessary(&line, i)) > 0)
			continue ;
		if (is_(NAME_CMD_STRING, &line[i]) && !name)
			name = get_quote(fd, line, ft_strlen(NAME_CMD_STRING) + i);
		else if (is_(COMMENT_CMD_STRING, &line[i]) && !comment)
			comment = get_quote(fd, line, ft_strlen(COMMENT_CMD_STRING) + i);
		else if (!name || !comment)
			error_exit("First two commands must be name and comment!", 1);
		ft_strdel(&line);
		if (name && comment)
			break ;
	}
	last_check_nc(name, comment, end);
	save_in_heder(header, name, comment);
}
