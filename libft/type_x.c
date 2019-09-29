/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 21:23:28 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 19:26:02 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*h_or_not_h(t_flags *flags, size_t nbr, size_t *len, const _Bool x)
{
	if (nbr == 0)
		flags->hash = 0;
	if (nbr == 0 && flags->have_precision && !flags->precision)
	{
		*len = 0;
		return (NULL);
	}
	return (itoa(nbr, len, 16, x));
}

void		type_x(t_printf *global, t_flags *flags)
{
	size_t		len_n;
	char		*hex;
	const _Bool	x = global->form[global->iter_frm] == 'x';
	const char	*hash = x ? "0x" : "0X";

	hex = h_or_not_h(flags, unsigned_nbr(flags, global->ap), &len_n, x);
	precision_count(flags, len_n);
	width_count(flags, len_n, (flags->hash ? 2 : 0));
	if (!flags->minus && !flags->zero && flags->have_width)
		add_in_buf_char(global, flags->width_char, flags->width);
	if (flags->hash)
		add_in_buf_str(global, (char*)hash, 2);
	if (!flags->minus && flags->zero && flags->have_width)
		add_in_buf_char(global, flags->width_char, flags->width);
	if (flags->have_precision)
		add_in_buf_char(global, '0', flags->precision);
	if (len_n)
		add_in_buf_str(global, (char*)hex, len_n);
	if (flags->minus && flags->have_width)
		add_in_buf_char(global, flags->width_char, flags->width);
	if (len_n)
		free(hex);
}
