/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_for_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:06:32 by solefir           #+#    #+#             */
/*   Updated: 2019/10/19 00:15:26 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			atoi_for_args(char **str)
{
	int		num;
	int		neg;

	num = 0;
	neg = 1;
	if (**str == '-')
	{
		neg = -1;
		(*str)++;
	}
	while (ft_isdigit(**str))
	{
		num = (num * 10) + ((**str) - '0');
		(*str)++;
	}
	return (num * neg);
}
