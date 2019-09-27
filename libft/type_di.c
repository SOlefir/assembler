/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 21:22:47 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 19:25:41 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sign(t_flags *flags)
{
	if (flags->negative)
		return ('-');
	else if (flags->plus)
		return ('+');
	else if (flags->space)
		return (' ');
	return (0);
}

void		type_di(t_printf *global, t_flags *flags)
{
	size_t		nbr;
	size_t		len_n;
	int			znak;

	nbr = signed_nbr(flags, global->ap);
	len_n = len_nbr(nbr);
	znak = sign(flags);
	if (nbr == 0 && flags->have_precision && !flags->precision)
		len_n = 0;
	precision_count(flags, len_n);
	width_count(flags, znak != 0, len_n);
	if (!flags->minus && !flags->zero && flags->have_width)
		add_in_buf_char(global, flags->width_char, flags->width);
	if (znak)
		add_in_buf_char(global, znak, 1);
	if (!flags->minus && flags->zero && flags->have_width)
		add_in_buf_char(global, flags->width_char, flags->width);
	if (flags->have_precision)
		add_in_buf_char(global, '0', flags->precision);
	if (len_n)
		add_in_buf_nbr(global, nbr, len_n);
	if (flags->minus && flags->have_width)
		add_in_buf_char(global, flags->width_char, flags->width);
}
