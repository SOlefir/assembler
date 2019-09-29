/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 21:18:10 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 19:25:37 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		type_c(t_printf *global, t_flags *flags)
{
	char	c;

	c = global->form[global->iter_frm];
	if (c == 'c')
		c = (char)va_arg(global->ap, int);
	if (flags->minus)
		add_in_buf_char(global, c, 1);
	if (flags->width - 1 > 0)
		add_in_buf_char(global, flags->width_char, flags->width - 1);
	if (!(flags->minus))
		add_in_buf_char(global, c, 1);
}
