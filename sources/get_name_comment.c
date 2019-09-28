/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:40:11 by solefir           #+#    #+#             */
/*   Updated: 2019/09/28 15:21:14 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static char *get_quote(int fd, char *str, int size_cmd)
{
	int		i;
	char 	*quot;
	char	*end_quot;
	char 	*line;

	end_quot = 0;
	i = size_cmd + skip_whitespaces(str);
	ft_printf("HERE");
	ft_printf("%i\n", i);
	if (str[i] == '"')
	{
		line = ft_strdup(&str[i]);
		ft_strdel(&str);
		quot = extract_from_quotes(fd, '"', &line);
	}
	else
		error_exit("Have`n quotes", 0);
	end_quot = ft_strchr(line, '"');
	i = skip_whitespaces(end_quot);
	if (end_quot[i] != '\0' || end_quot[i] != COMMENT_CHAR)
		error_exit("garbadge after quotes", i);
	ft_strdel(&line);
	return (quot);
}

static void	save_in_heder(t_header **header, char *name, char *comment)
 {
 	int 	i;

 	i = 0;
 	ft_printf("%s\n$s\n", name, comment);
 	if (!name || !comment)
 		error_exit(ft_strjoin("There is no ", name ? "comment." : "name."), 0);
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
}

void		get_name_comment(int fd, t_header **header)
{
	int 	i;
	char	*line;
	char 	*name;
	char 	*comment;

	line = NULL;
	comment = NULL;
	name = NULL;
	while (get_next_line(fd, &line) >= 0 && (i = skip_whitespaces(line)))
	{
		g_str_n++;
		if (is_unnecessary(&line, i))
			continue ;
		if (is_name(line))
			name = get_quote(fd, line, ft_strlen(NAME_CMD_STRING));
		else if (is_comment(line))
			comment = get_quote(fd, line, ft_strlen(COMMENT_CMD_STRING));
		ft_strdel(&line);
		if ((name && comment) || (!name && !comment))
			break ;
	}
	save_in_heder(header, name, comment);
	ft_strdel(&name);
 	ft_strdel(&comment);
}
