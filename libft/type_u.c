/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 21:23:40 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 19:25:58 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		type_u(t_printf *global, t_flags *flags)
{
	size_t		nbr;
	size_t		len_n;

	nbr = unsigned_nbr(flags, global->ap);
	if (nbr == 0 && flags->have_precision && !flags->precision)
		len_n = 0;
	else
		len_n = len_nbr(nbr);
	precision_count(flags, len_n);
	width_count(flags, len_n, 0);
	if (!flags->minus && flags->have_width)
		add_in_buf_char(global, flags->width_char, flags->width);
	if (flags->have_precision)
		add_in_buf_char(global, '0', flags->precision);
	if (len_n)
		add_in_buf_nbr(global, nbr, len_n);
	if (flags->minus && flags->have_width)
		add_in_buf_char(global, flags->width_char, flags->width);
}
