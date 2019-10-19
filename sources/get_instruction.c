/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:24:44 by solefir           #+#    #+#             */
/*   Updated: 2019/10/19 20:32:58 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_line(t_op *op, char *label_name, char *line)
{
	char	*second_lbl;

	second_lbl = is_label(line);
	if (is_(NAME_CMD_STRING, line))
		error_exit("Repeat name command!", 1);
	if (is_(COMMENT_CMD_STRING, line))
		error_exit("Repeat comment command!", 1);
	if (label_name && second_lbl)
		error_exit("Label in one line with second label", 1);
	if (label_name && *line == SEPARATOR_CHAR)
		error_exit("The separator character must be only between arguments", 1);
	if (!op && !label_name)
		error_exit("Unknown command!", 1);
}

void	check_eof(int fd)
{
	char	buff[1];

	buff[0] = '\0';
	lseek(fd, (long long)-1, 2);
	read(fd, buff, 1);
	if (buff[0] != '\n')
		error_exit("File must end with a single empty line", 0);
}

void	get_instruction(int fd, t_holder *holder)
{
	char	*line;
	char	*label_name;
	t_op	*op;
	int		i;

	line = NULL;
	while (get_next_line(fd, &line) > 0 && (i = skip_whitespaces(line)) >= 0)
	{
		label_name = NULL;
		op = NULL;
		g_str_n++;
		if (is_unnecessary(&line, i))
			continue ;
		if ((label_name = is_label(&line[i])))
		{
			save_label(&(holder->labels), label_name, holder->bytes_count + 1);
			i += ft_strlen(label_name) + 1;
			i += skip_whitespaces(&line[i]);
		}
		if ((op = find_op(&line[i])))
			save_instruction_code(&line[i], holder, op);
		check_line(op, label_name, &line[i]);
		ft_strdel(&line);
	}
	check_eof(fd);
}
