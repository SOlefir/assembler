/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_in_buf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:02:08 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 19:26:15 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_in_buf_nbr(t_printf *global, size_t nbr, size_t len_nbr)
{
	size_t	temp;

	temp = len_nbr;
	while (len_nbr > 0)
	{
		if (global->buf_size == PRINTF_BUFF_SIZE ||
			global->buf_size + len_nbr >= PRINTF_BUFF_SIZE)
			print_buf(global);
		len_nbr--;
		global->buf[len_nbr + global->buf_size] = '0' + (nbr % 10);
		nbr = nbr / 10;
	}
	global->buf_size += temp;
	global->ret += temp;
}

void	add_in_buf_str(t_printf *global, char *str, int len)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		if (global->buf_size == PRINTF_BUFF_SIZE)
			print_buf(global);
		global->buf[global->buf_size] = str[i];
		len--;
		i++;
		global->buf_size++;
		global->ret++;
	}
}

void	add_in_buf_char(t_printf *global, char c, int count)
{
	while (count > 0)
	{
		if (global->buf_size == PRINTF_BUFF_SIZE)
			print_buf(global);
		global->buf[global->buf_size] = c;
		count--;
		global->buf_size++;
		global->ret++;
	}
}
