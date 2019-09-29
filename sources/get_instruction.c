/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:24:44 by solefir           #+#    #+#             */
/*   Updated: 2019/09/29 22:35:46 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	get_instruction(int fd_arg, t_holder **holder)
{
	char	*line;
	char	*label;
	int		len_lbl;
	int		i;

	line = NULL;
	label = NULL;
	while (get_next_line(fd_arg, &line) && (i = skip_whitespaces(line)) >= 0)
	{
		g_str_n++;
		if (is_unnecessary(&line, i))
			continue ;
		if (len_lbl = is_label(&line[i]))
		{
			label = ft_strdup(&line[i], len_lbl);
			if (is_instruction(&line[i + len_lbl]))
				save_instruction_code(&line[i + len_lbl], &holder, label);
		}
		else if (is_instruction(&line[i]))
			save_instruction_code(&line[i], &holder, label);
		ft_strdel(&line);
		if (!(holder->binary->code) && !label)
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
