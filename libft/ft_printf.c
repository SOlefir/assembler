/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:17:07 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 19:28:33 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		in_buf(t_printf *global)
{
	int	len;

	len = 0;
	while (global->form[global->iter_frm] &&
			global->form[global->iter_frm] != '%')
	{
		global->iter_frm++;
		len++;
	}
	if (len >= PRINTF_BUFF_SIZE ||
		len + global->buf_size >= PRINTF_BUFF_SIZE)
		print_buf_and_form(global, global->form + global->iter_frm - len, len);
	else
	{
		ft_memcpy((void*)(global->buf + global->buf_size),
				(void*)(global->form + global->iter_frm - len), (size_t)len);
		global->buf_size += len;
		global->ret += len;
	}
}

static void		parse_str(t_printf *global)
{
	while (global->form[global->iter_frm])
	{
		if (global->form[global->iter_frm] == '%')
		{
			global->iter_frm++;
			parse_arg(global);
			if (global->form[global->iter_frm])
				global->iter_frm++;
		}
		else
			in_buf(global);
	}
}

int				ft_printf(char *format, ...)
{
	t_printf	global;

	ft_bzero((void*)&global, sizeof(t_printf));
	va_start(global.ap, format);
	global.buf = (char*)malloc(PRINTF_BUFF_SIZE);
	global.form = format;
	parse_str(&global);
	va_end(global.ap);
	if (global.buf_size > 0)
		write(1, global.buf, global.buf_size);
	free(global.buf);
	return (global.ret);
}
