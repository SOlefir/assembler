/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:24:44 by solefir           #+#    #+#             */
/*   Updated: 2019/10/19 16:52:43 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_line(t_op *op, char *label_name)
{
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
		check_line(op, label_name);
		ft_strdel(&line);
	}
	check_eof(fd);
}
