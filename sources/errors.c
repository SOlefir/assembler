/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:00:32 by solefir           #+#    #+#             */
/*   Updated: 2019/09/28 21:42:20 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	error_exit(char *message, int byte)
{
	int i;

	i = 0;
	(void)byte;
	//write(1, "HEy\n", 4);
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\nLine: ", 2);
	ft_putnbr_fd(g_str_n, 2);
	// ft_putstr_fd("col ", 2);
	// ft_putnbr_fd(byte, 2);
	ft_putchar_fd('\n', 2);
	//ft_putstr_fd(massage, 2);
	//system("leaks asm");
	exit(2);
}
