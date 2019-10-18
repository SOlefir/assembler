/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:00:32 by solefir           #+#    #+#             */
/*   Updated: 2019/10/18 21:22:53 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

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
