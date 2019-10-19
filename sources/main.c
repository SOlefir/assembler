/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:00:46 by solefir           #+#    #+#             */
/*   Updated: 2019/10/19 23:31:05 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	g_str_n = 0;

static _Bool	s_file(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
		i++;
	if (arg[i - 2] == '.' && arg[i - 1] == 's')
		return (1);
	return (0);
}

int				main(int ac, char **av)
{
	t_holder	*holder;
	int			fd_arg;

	if (ac != 2)
		error_exit("No file", 0);
	if (!s_file(av[1]))
		error_exit("Invalid file. Expected file extension '.s'", 0);
	if ((fd_arg = open(av[1], O_RDONLY)) < 0)
		error_exit("Сan't read file", 0);
	holder = init_holder();
	get_name_comment(fd_arg, holder->header);
	get_instruction(fd_arg, holder);
	label_input(holder->code, holder->labels);
	write_in_file(make_name(av[1]), holder);
	return (0);
}
