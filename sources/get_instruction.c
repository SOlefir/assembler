/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:24:44 by solefir           #+#    #+#             */
/*   Updated: 2019/10/16 15:04:45 by solefir          ###   ########.fr       */
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
	holder->bytes_count = -1;
	while (get_next_line(fd_arg, &line) && (i = skip_whitespaces(line)) >= 0)
	{
		label_name = NULL;
		op = NULL;
		g_str_n++;
		if (is_unnecessary(&line, i))
			continue ;
		if ((label_name = is_label(&line[i])))
		{
			save_label(NULL, label_name, holder->bytes_count + 1,
															&(holder->labels));
			holder->labels->value = holder->bytes_count;
			i += skip_whitespaces(line);
		}
		if ((op = find_op(&line[i])))
			save_instruction_code(&line[i], holder, op);
		ft_strdel(&line);
		if (!(holder->code->code) && !label_name)
			break ;
	}
}

// 0. считываю строку
// 	1. распознаю команды, 
// 		- проверяю аргументы
// 		- подсчитываю кол-во байт ск надо будет выделить память на строку
// 		- перевожу в код
// 		- встретив метку - отправляю в фнк save_lbl на этом месте в коде 
// 		ставлю 0000, сохраняю это место
// 	2. если не конец файла, то команда 0.
