/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:40:11 by solefir           #+#    #+#             */
/*   Updated: 2019/10/19 16:56:58 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void		last_check_nc(char *name, char *comment)
{
	if (name == NULL && comment == NULL)
		error_exit("No name and comment command or used of unknown command!",
																			1);
	if (!name)
		error_exit("No name command!", 1);
	if (!comment)
		error_exit("No comment command!", 1);
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
		error_exit("Quotes have error!", 1);
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
	char	*line;
	char	*name;
	char	*comment;

	line = NULL;
	comment = NULL;
	name = NULL;
	while (get_next_line(fd, &line) && (i = skip_whitespaces(line)) >= 0)
	{
		g_str_n++;
		if (is_unnecessary(&line, i))
			continue ;
		if (is_(NAME_CMD_STRING, &line[i]) && !name)
			name = get_quote(fd, line, ft_strlen(NAME_CMD_STRING) + i);
		else if (is_(COMMENT_CMD_STRING, &line[i]) && !comment)
			comment = get_quote(fd, line, ft_strlen(COMMENT_CMD_STRING) + i);
		else if (!name || !comment)
			break ;
		if (name && comment)
			break ;
	}
	last_check_nc(name, comment);
	save_in_heder(header, name, comment);
}
