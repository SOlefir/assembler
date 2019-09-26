/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:40:11 by solefir           #+#    #+#             */
/*   Updated: 2019/09/18 14:11:17 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static char *get_binary_nc(int fd, char **str, int size_cmd)
{
	int		i;
	char 	*quot;
	char	*end_quot;

	end_quot = 0;
	i = size_cmd;
	while (ft_iswhitespace((*str)[i]))
		i++;
	if ((*str)[i] == '"')
		quot = extract_from_quots(fd, '"', &str[i]);
	else
		error_exit("Have`n quotes");
	end_quot = ft_strchr(str, '"');
	skip_whitespaces(&end_quot);
	if (*end_quot != '\0' || *end_quot != COMMENT_CHAR)
		error_exit("garbadge after quotes");
	ft_strdel(&str);
	return (quote);
}

static void	save_in_heder(t_header **header, char *name, char *comment)
 {
 	int 	i;

 	i = 0;
 	if (!name || !comment)
 		error_exit(ft_strjoin("Have`n ", name ? "comment." : "name."));
 	while (++i <= PROG_NAME_LENGTH + 1)
 		if (name[i])
 			header->prog_name[i] = name[i];
 		else
 			header->prog_name[i] = 0;
 	i = 0;
 	while (++i <= COMMENT_LENGTH + 1)
 		if (comment[i])
 			header->comment[i] = comment[i];
 		else
 			header->comment[i] = 0;
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
	while (get_next_line(fd, &line) >= 0 && (i = skeep_iswhitespace(line)))
	{
		g_str_n++;
		if (is_unnessery(&line, i))
			continue ;
		if (is_name(line))
			name = get_nc(fd, &line, ft_strlen(NAME_CMD_STRING));
		else if (is_comment(line))
			comment = get_nc(fd, &line, ft_strlen(COMMENT_CMD_STRING));
		ft_strdel(&line);
		if ((name && comment) || (!name && !comment))
			break ;
	}
	save_in_heder(&header, name, comment);
	ft_strdel(&name);
 	ft_strdel(&comment);
}
