/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:26:02 by solefir           #+#    #+#             */
/*   Updated: 2019/09/29 16:48:41 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	g_str_n = 0;
int	g_byte_n = 0;

int		main(int ac, char **av)
{
	t_holder	*holder;
	int			fd_arg;

	if (ac != 2)
		error_exit("arg_error", 0);
	if ((fd_arg = open(av[1], O_RDONLY)) < 0)// проверка .s
		error_exit("read_error", 0);
	holder = init_holder();
	get_name_comment(fd_arg, &holder->header);
	//get_instruction(fd_arg, &holder);
	// insert_lables(&holder);
	// close(fd_arg);
	// write_in_file(make_name(av[1]), holder);
	//system("leaks asm");
	return (0);
}
