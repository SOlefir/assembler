/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:00:32 by solefir           #+#    #+#             */
/*   Updated: 2019/09/28 16:51:39 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	error_exit(char *massage, int byte)
{
	int i;

	i = 0;
	write(1, "HEy\n", 4);
	ft_putstr_fd("ERROR: \n      str ", 2);
	ft_putnbr_fd(g_str_n, 2);
	ft_putstr_fd("col ", 2);
	ft_putnbr_fd(byte, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd(massage, 2);
	exit(2);
}
