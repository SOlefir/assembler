/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 21:23:50 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 19:25:55 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		type_s(t_printf *global, t_flags *flags)
{
	global->str = (char *)va_arg(global->ap, char*);
	if (global->str == NULL)
	{
		global->str = "(null)";
		global->str_len = 6;
	}
	else
		global->str_len = (int)ft_strlen(global->str);
	if (flags->have_precision && global->str_len &&
		global->str_len > flags->precision)
		global->str_len = flags->precision;
	if (flags->minus && global->str_len)
		add_in_buf_str(global, global->str, global->str_len);
	if (flags->have_width && flags->width - global->str_len > 0)
		add_in_buf_char(global, flags->width_char,
						flags->width - global->str_len);
	if (!(flags->minus) && global->str_len)
		add_in_buf_str(global, global->str, global->str_len);
}
