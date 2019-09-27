/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:28:06 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 19:25:02 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*itoa(size_t nbr, size_t *len_str, int notation, const _Bool low)
{
	char		*str;
	const char	*letters = low ? "0123456789abcdef" : "0123456789ABCDEF";
	size_t		temp_nb;

	temp_nb = nbr / notation;
	*len_str = 1;
	while (temp_nb)
	{
		temp_nb /= notation;
		(*len_str)++;
	}
	str = (char*)malloc(*len_str + 1);
	temp_nb = *len_str;
	while (temp_nb)
	{
		temp_nb--;
		str[temp_nb] = letters[nbr % notation];
		nbr /= notation;
	}
	str[*len_str] = '\0';
	return (str);
}

size_t		unsigned_nbr(t_flags *flags, va_list ap)
{
	size_t	nbr;

	if (flags->z)
		nbr = va_arg(ap, size_t);
	else if (flags->j)
		nbr = (size_t)va_arg(ap, uintmax_t);
	else if (flags->ll)
		nbr = (size_t)va_arg(ap, unsigned long long);
	else if (flags->l)
		nbr = (size_t)va_arg(ap, unsigned long);
	else if (flags->h)
		nbr = (size_t)((unsigned short)va_arg(ap, unsigned int));
	else if (flags->hh)
		nbr = (size_t)((unsigned char)va_arg(ap, unsigned int));
	else
		nbr = (size_t)va_arg(ap, unsigned int);
	return (nbr);
}

size_t		signed_nbr(t_flags *flags, va_list ap)
{
	intmax_t	temp;
	size_t		nbr;

	if (flags->z || flags->j)
		temp = va_arg(ap, intmax_t);
	else if (flags->ll)
		temp = (intmax_t)va_arg(ap, long long);
	else if (flags->l)
		temp = (intmax_t)va_arg(ap, long);
	else if (flags->h)
		temp = (intmax_t)((short)va_arg(ap, int));
	else if (flags->hh)
		temp = (intmax_t)((char)va_arg(ap, int));
	else
		temp = (intmax_t)va_arg(ap, int);
	flags->negative = temp < 0;
	nbr = (size_t)(temp < 0 ? -temp : temp);
	return (nbr);
}
