/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:40:11 by solefir           #+#    #+#             */
/*   Updated: 2019/09/28 20:18:39 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static char *get_quote(int fd, char *line, int size_cmd)
{
	int		i;
	char 	*quot;
	char	*end_quot;
	char 	*temp;

	end_quot = 0;
	quot = NULL;
	i = size_cmd; 
	i += skip_whitespaces(&line[i]);
	ft_printf("%s\n", &line[i]);//
	if (line[i++] == '"')
	{
		temp = ft_strdup(&line[i]);
		quot = extract_from_quotes(fd, '"', &temp);
	}
	else
		error_exit("Have`n quotes", 0);
	end_quot = ft_strchr(temp, '"');
	ft_printf("end_quot: [%c] %s\n", end_quot[0], end_quot);//
	i = skip_whitespaces(end_quot) + 1;
	// ft_printf("%d\n", i);//
	ft_printf("quot->%s\n", quot);//
	if (end_quot[i] != '\0' && end_quot[i] != COMMENT_CHAR)
		error_exit("garbadge after quotes", (int)(&end_quot[i] - temp + size_cmd)); //еще пробелы посчитать 
	ft_strdel(&temp);
	return (quot);
}

static void	save_in_heder(t_header **header, char *name, char *comment)
 {
 	int 	i;

 	i = 0;
 	ft_printf("\nname: %s\ncomment: %s\n", name, comment);
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
	ft_printf("\n_____________\n");
	while (get_next_line(fd, &line) >= 0 && (i = skip_whitespaces(line)) >= 0)
	{
		g_str_n++;
		if (is_unnecessary(&line, i))
			continue ;
		if (is_(NAME_CMD_STRING, &line[i]))
			name = get_quote(fd, line, ft_strlen(NAME_CMD_STRING) + i);
		else if (is_(COMMENT_CMD_STRING, &line[i]))
			comment = get_quote(fd, line, ft_strlen(COMMENT_CMD_STRING) + i);
		//ft_strdel(&line);
		if ((name && comment) || (!name && !comment))
		 	break ;
	}
	//ft_printf("%s\n$s\n", name, comment);
	save_in_heder(header, name, comment);
	ft_strdel(&name);
 	ft_strdel(&comment);
}
