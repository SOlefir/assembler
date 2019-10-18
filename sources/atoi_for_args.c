/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_for_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:06:32 by solefir           #+#    #+#             */
/*   Updated: 2019/10/17 18:26:26 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			atoi_for_args(char **str, char end)
{
	int		num;
	int		neg;
	int		i;

	num = 0;
	i = 1;
	neg = 1;
	if (**str == '-')
	{
		neg = -1;
		(*str)++;
	}
	while (**str != end && **str != '\0')
	{
		num *= i;
		num += **str - '0';
		i *= 10;
		(*str)++;
	}
	return (num * neg);
}
