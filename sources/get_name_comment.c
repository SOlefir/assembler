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

#include "asm.h"

static char extract_from_quots(int fd, char **quot)
{
	3. конкотинировать строку до закрывающихся скобок
	4. если конец файла, а скобок нет, то нахуй это ошибка	
}

static char get_nc_qouots(int fd, char **str)
{
	int		i;
	int		end_quot;
	int		start_quot;
	char 	*quot;

	end_quot = 0;
	if (!(is_name(*str) && i = ft_strlen(NAME_CMD_STRING)) && 
		!(is_comment(*str) && i = ft_strlen(COMMENT_CMD_STRING)))
			error ("garbage");
	while (is_whitespase((*str)[i]))
		i++;
	if ((start_quot = 0) && (*str)[i] == '"')
	{
		start_quot = i + 1;
		while ((end_quot = ++i) && (*str)[i] != '\0')
			if ((*str)[i] == '"')
			{
				while (is_whitespase((*str)[++i]));
				if ((*str)[i] != '\0')
					error();
			}
	}
	quot = start_quot ? ft_strsub(*str, start_quot, end_quot - start_quot) :
			error();
	ft_strdel(*str);
	return (end_quot ? quot : extract_from_quots(fd, &quot));
}

static void	make_binary_nc(t_header **header, char *name, char *comment)
{
	char	*binary;
	int 	i;

	i = 0;
	binary = make_binary(name);
	while (++i <= PROG_NAME_LENGTH + 1)
		if (binary[i])
			head->prog_name[i] = binary[i];
		else
			head->prog_name[i] = 0;
	i = 0;
	ft_strdel(binary);
	binary = make_binary(comment);
	while (++j <= COMMENT_LENGTH + 1)
		if (binary[i])
			head->comment[i] = binary[i];
		else
			head->comment[i] = 0;
	ft_strdel(binary);
}

void		get_name_comment(int fd, t_header **header)
{
	int 	i;
	char	*line;

	while (get_next_line(fd, &line) > 0 && (g_str_n++))
	{
		i = 0;
		while (is_whitespase(line[i]))
			i++;
		if (line[i] == COMMENT_CHAR)
		{
			ft_strdel(line);	
			continue ;
		}
		if (line[i] == NAME_CMD_STRING[0] && line[i + 1] == NAME_CMD_STRING[0])
			name = get_nc_qouots(fd, &line);
		else if (line[i] == COMMENT_CMD_STRING[0] &&
				line[i + 1] == COMMENT_CMD_STRING[1])
			comment = get_nc_qouots(fd, &line);
		ft_strdel(line);
		if ((name && comment) || (!name && !comment))
			break ;
	}
	make_binary_nc(&header, name, comment); // проверить на наличие имени и коммента 
}
