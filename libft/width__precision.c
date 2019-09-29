/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width__precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:14:44 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 19:27:54 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	width_count(t_flags *flags, unsigned int znak, size_t len_nbr)
{
	int	i;

	i = flags->width - flags->precision - (int)len_nbr - znak;
	if (i <= 0)
	{
		flags->have_width = 0;
		flags->width = 0;
	}
	else
		flags->width = i;
}

void	precision_count(t_flags *flags, size_t len_nbr)
{
	int	i;

	i = flags->precision - (int)len_nbr;
	if (i <= 0)
	{
		flags->have_precision = 0;
		flags->precision = 0;
	}
	else
		flags->precision = i;
}
