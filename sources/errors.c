/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:40:11 by solefir           #+#    #+#             */
/*   Updated: 2019/09/18 14:11:17 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	error_exit(char *massage, int byte)
{
	int i;

	i = 0;
	ft_putstr_fd("ERROR: \n     str ", 2);
	ft_putnbr_fd(g_str_n, 2);
	ft_putstr_fd("col ", 2);
	ft_putnbr_fd(byte, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd(massage, 2);
	exit(2);
}
