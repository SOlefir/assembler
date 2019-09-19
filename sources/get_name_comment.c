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

static char get_name(int fd, char *str)
{
	1. проверить название команды. если не имя, то нахуй это ошибка
	2. проверить лишние символы до скобок
	3. конкотинировать строку до закрывающихся скобок
	4. если конец файла, а скобок нет, то нахуй это ошибка
	
}

static char get_comment(int fd, char *str)
{
	
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
			name = get_name(fd, line);
		else if (line[i] == COMMENT_CMD_STRING[0] && line[i + 1] == COMMENT_CMD_STRING[1])
			comment = get_comment(fd, line);
		ft_strdel(line);
		if ((name && comment) || (!name && !comment))
			break ;
	}
	make_binary_nc(&header, name, comment);
}

// char		*get_nc(int fd, t_header *header) //можно найти сразу и имя и коммент, но если флаг - нейм, то вернуть имя, а коммент сохранить в статику
// {
// 	char		*comment;
// 	char		*name;
// 	char		temp;
// 	int			j;

// 	comment = NULL;
// 	name = NULL;
// 	j = -1;
// 	check_nc(file);//на повторы, мусор, отсутствие какой-то команды, расположение внутри кода
// 	while (!is_lable(file[++j]) || !is_instruction(file[j]))
// 	{
// 		if (is_name(file[j]))
// 			name = extract_quots(file, &j);
// 		if (is_comment(file[j]))
// 			comment = extract_quots(file, &j);
// 	}
// 	get_binary_nc(&header->comment, comment, COMMENT_LENGTH + 1);
// 	get_binary_nc(&header->name, name, PROG_NAME_LENGTH + 1);
// }

