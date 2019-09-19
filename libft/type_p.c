/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 21:23:58 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 19:25:50 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*p_or_not_p(t_flags *flags, size_t nbr, size_t *len)
{
	if (nbr == 0 && flags->have_precision && !flags->precision)
	{
		*len = 0;
		return (NULL);
	}
	return (itoa(nbr, len, 16, 1));
}

void		type_p(t_printf *global, t_flags *flags)
{
	size_t		len_n;
	char		*point;

	flags->l = 1;
	point = p_or_not_p(flags, unsigned_nbr(flags, global->ap), &len_n);
	precision_count(flags, len_n);
	width_count(flags, len_n, 2);
	if (!flags->minus && !flags->zero && flags->have_width)
		add_in_buf_char(global, flags->width_char, flags->width);
	add_in_buf_str(global, "0x", 2);
	if (!flags->minus && flags->zero && flags->have_width)
		add_in_buf_char(global, flags->width_char, flags->width);
	if (flags->have_precision)
		add_in_buf_char(global, '0', flags->precision);
	if (len_n)
		add_in_buf_str(global, point, len_n);
	if (flags->minus && flags->have_width)
		add_in_buf_char(global, flags->width_char, flags->width);
	if (len_n)
		free(point);
}
