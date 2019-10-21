/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:00:32 by solefir           #+#    #+#             */
/*   Updated: 2019/10/20 15:02:20 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	errors_in_args(char *instr)
{
	if (*instr == '%' || *instr == 'r' || *instr == LABEL_CHAR ||
		ft_isdigit((int)*instr) || *instr == '-')
		error_exit("Invalid argument type", 1);
	else if (*instr != '\0' && *instr != COMMENT_CHAR &&
			*instr != ALT_COMMENT_CHAR)
		error_exit("Incorrect character in arguments", 1);
}

void	error_exit(char *message, int str)
{
	int i;

	i = 0;
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(message, 2);
	if (str)
	{
		ft_putstr_fd("\nOn line: ", 2);
		ft_putnbr_fd(g_str_n, 2);
	}
	ft_putchar_fd('\n', 2);
	exit(2);
}
