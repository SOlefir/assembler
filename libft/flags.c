/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:05:50 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 19:28:18 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ignor_or_not_ignor(t_flags *flags, char c)
{
	if (flags->h_counter && flags->h_counter % 2 == 1)
		flags->h = 1;
	else if (flags->h_counter)
		flags->hh = 1;
	if ((flags->l_counter && flags->l_counter % 2 == 1) ||
		c == 'D' || c == 'O' || c == 'U')
		flags->l = 1;
	else if (flags->l_counter)
		flags->ll = 1;
	if (flags->plus == 1)
		flags->space = 0;
	if (((c == 'd' || c == 'p' || c == 'D' || c == 'i' || c == 'o' ||
	c == 'O' || c == 'x' || c == 'X' || c == 'u' || c == 'U') &&
	flags->have_precision) || flags->minus == 1)
		flags->zero = 0;
	flags->width_char = flags->zero ? '0' : ' ';
}

static void		width(t_printf *global, t_flags *flags)
{
	size_t	nb;

	nb = 0;
	flags->have_width = 1;
	while (global->form[global->iter_frm] >= '0' &&
			global->form[global->iter_frm] <= '9')
	{
		nb = nb * 10 + (global->form[global->iter_frm] - '0');
		global->iter_frm++;
	}
	flags->width = (int)nb;
}

static void		precision(t_printf *global, t_flags *flags)
{
	size_t	nb;

	nb = 0;
	flags->have_precision = 1;
	global->iter_frm++;
	while (global->form[global->iter_frm] == '0')
		global->iter_frm++;
	while (global->form[global->iter_frm] >= '0' &&
			global->form[global->iter_frm] <= '9')
	{
		nb = nb * 10 + (global->form[global->iter_frm] - '0');
		global->iter_frm++;
	}
	flags->precision = (int)nb;
}

static void		get_flags(t_flags *flags, char c)
{
	if (c == '#')
		flags->hash = 1;
	else if (c == '0')
		flags->zero = 1;
	else if (c == '-')
		flags->minus = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == 'h')
		flags->h_counter++;
	else if (c == 'l')
		flags->l_counter++;
	else if (c == 'j')
		flags->j = 1;
	else if (c == 'z')
		flags->z = 1;
	else
		flags->big_l = 1;
}

void			find_flags(t_printf *global, t_flags *flags)
{
	char c;

	c = global->form[global->iter_frm];
	while (c == ' ' || c == '#' || c == '+' || c == '-' || c == '.' ||
		(c >= '0' && c <= '9') || c == 'h' || c == 'l' || c == 'j' ||
		c == 'z' || c == 'L')
	{
		if (c == ' ' || c == '#' || c == '+' || c == '-' || c == '0' ||
		c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 'L')
		{
			get_flags(flags, c);
			global->iter_frm++;
		}
		else if (c == '.')
			precision(global, flags);
		else
			width(global, flags);
		c = global->form[global->iter_frm];
	}
	ignor_or_not_ignor(flags, c);
}
