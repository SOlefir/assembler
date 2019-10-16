/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_for_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:06:32 by solefir           #+#    #+#             */
/*   Updated: 2019/10/16 15:23:04 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			atoi_for_args(char **str, char end)
{
	int		num;
	int		neg;

	num = 0;
	neg = (**str == '-') ? -1 : 1;
	(*str)++;
	while (**str != end && (**str >= '0' && **str <= '9'))
	{
		num = num * 10 + (int)**str - (int)'0';
		(*str)++;
	}
	return (num * neg);
}
