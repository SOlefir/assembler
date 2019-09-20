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

static char *extract_from_quots(int fd, char **quot)
{

	int 	i;
	int 	end_quot;
	char 	*line;
	char 	*temp;

	i = -1;
	line = NULL;
	end_quot = 0;
	while (!end_quot && get_next_line(fd, &line) > 0)
	{
		while ((*quot)[++i] != '\0')
			if ((*quot)[i] == '"' && (end_quot++))
				break ;
		if (end_quot)
		{	
			while (ft_iswhitespace((*quot)[++i]));
			if ((*quot)[i] != '\0')
					ft_printf("error quot\n");
		}
		temp = ft_strncat(line, *quot, i);
		ft_strdel(&line);
		ft_strdel(quot);
	}
	return (temp);
}

static char *get_nc_qouots(int fd, char **str)
{
	int		i;
	int		end_quot;
	int		start_quot;
	char 	*quot;

	end_quot = 0;
	ft_printf("HERE\n");
	if (!(is_name(*str) && (i = ft_strlen(NAME_CMD_STRING))) && 
		!(is_comment(*str) && (i = ft_strlen(COMMENT_CMD_STRING))))
			ft_printf ("garbage\n");
	while (ft_iswhitespace((*str)[i]))
		i++;
	if ((start_quot = 0) && (*str)[i] == '"')
	{
		start_quot = i + 1;
		while ((end_quot = ++i) && (*str)[i] != '\0')
			if ((*str)[i] == '"')
			{
				while (ft_iswhitespace((*str)[++i]));
				if ((*str)[i] != '\0')
					ft_printf("end_quot\n");
			}
	}
	if (!(quot = ft_strsub(*str, start_quot, end_quot - start_quot)))
		ft_printf("error quot\n");
	ft_strdel(str);
	return (end_quot ? quot : extract_from_quots(fd, &quot));
}

// static void	make_binary_nc(t_header **header, char *name, char *comment)
// {
// 	char	*binary;
// 	int 	i;

// 	i = 0;
// 	binary = make_binary(name);
// 	while (++i <= PROG_NAME_LENGTH + 1)
// 		if (binary[i])
// 			header->prog_name[i] = binary[i];
// 		else
// 			header->prog_name[i] = 0;
// 	i = 0;
// 	ft_strdel(&binary);
// 	binary = make_binary(comment);
// 	while (++i <= COMMENT_LENGTH + 1)
// 		if (binary[i])
// 			header->comment[i] = binary[i];
// 		else
// 			header->comment[i] = 0;
// 	ft_strdel(&binary);
// }

void		get_name_comment(int fd, t_header **header)
{
	int 	i;
	char	*line;
	char 	*name;
	char 	*comment;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		g_str_n++;
		i = 0;
		while (ft_iswhitespace(line[i]))
			i++;
		if (line[i] == COMMENT_CHAR)
		{
			ft_strdel(&line);	
			continue ;
		}
		if (line[i] == NAME_CMD_STRING[0])// && line[i + 1] == NAME_CMD_STRING[1])
			name = get_nc_qouots(fd, &line);
		else if (line[i] == COMMENT_CMD_STRING[0]) //&&
				//line[i + 1] == COMMENT_CMD_STRING[1])
			comment = get_nc_qouots(fd, &line);
		ft_strdel(&line);
		if ((name && comment) || (!name && !comment))
			break ;
	}
	ft_printf("name: %s\n", name);
	ft_printf("comment: %s\n", comment);
	//make_binary_nc(&header, name, comment); // проверить на наличие имени и коммента 
}
