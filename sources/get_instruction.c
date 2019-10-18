/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:24:44 by solefir           #+#    #+#             */
/*   Updated: 2019/10/18 22:52:22 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	get_instruction(int fd_arg, t_holder *holder)
{
	char	*line;
	char	*label_name;
	t_op	*op;
	int		i;

	line = NULL;
	holder->bytes_count = 0;
	while (get_next_line(fd_arg, &line) && (i = skip_whitespaces(line)) >= 0)
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
		printf("LINE [%s]\n", &line[i]);
		if ((op = find_op(&line[i])))
			save_instruction_code(&line[i], holder, op);
		if (!op && !label_name)
			error_exit("Unknown command!", 1);
		ft_strdel(&line);
	}
}
