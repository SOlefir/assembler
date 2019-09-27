/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:00:37 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 20:34:32 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# define PRINTF_BUFF_SIZE 4056

typedef struct s_printf	t_printf;
typedef struct s_flags	t_flags;

struct				s_printf
{
	int				iter_frm;
	int				buf_size;
	int				ret;
	char			*str;
	int				str_len;
	char			*form;
	char			*buf;
	va_list			ap;
};

struct				s_flags
{
	unsigned char	space : 1;
	unsigned char	hash : 1;
	unsigned char	plus : 1;
	unsigned char	minus : 1;
	unsigned char	zero : 1;
	unsigned char	have_precision : 1;
	unsigned char	have_width : 1;
	unsigned char	negative : 1;
	unsigned char	hh : 1;
	unsigned char	h : 1;
	unsigned char	l : 1;
	unsigned char	ll : 1;
	unsigned char	j : 1;
	unsigned char	z : 1;
	unsigned char	big_l : 1;

	int				h_counter;
	int				l_counter;
	int				precision;
	int				width;
	char			width_char;
};

int					ft_printf(char *format, ...);

void				print_buf_and_form(t_printf *global, char *str, int len);
void				print_buf(t_printf *global);
void				parse_arg(t_printf *global);
void				find_flags(t_printf *global, t_flags *flags);

void				specifier(t_printf *global, t_flags *flags);
void				width_count(t_flags *flags, unsigned int znak,
															size_t len_nbr);
void				precision_count(t_flags *flags, size_t len_nbr);

void				type_c(t_printf *global, t_flags *flags);
void				type_s(t_printf *global, t_flags *flags);
void				type_di(t_printf *global, t_flags *flags);
void				type_o(t_printf *global, t_flags *flags);
void				type_x(t_printf *global, t_flags *flags);
void				type_u(t_printf *global, t_flags *flags);
void				type_p(t_printf *global, t_flags *flags);

void				add_in_buf_char(t_printf *global, char c, int count);
void				add_in_buf_str(t_printf *global, char *str, int len);
void				add_in_buf_nbr(t_printf *global, size_t nbr,
															size_t len_nbr);
size_t				unsigned_nbr(t_flags *flags, va_list ap);
size_t				signed_nbr(t_flags *flags, va_list ap);
size_t				len_nbr(size_t nbr);
char				*itoa(size_t nbr, size_t *len_str, int notation,
															const _Bool low);

#endif
