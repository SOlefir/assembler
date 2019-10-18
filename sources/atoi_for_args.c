/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_for_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:06:32 by solefir           #+#    #+#             */
/*   Updated: 2019/10/18 21:58:13 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			atoi_for_args(char **str)
{
	int		num;
	int		neg;

	num = 0;
	neg = 1;
	printf("\n ATOI  \n");
	printf("str %s\n", *str);
	if (**str == '-')
	{
		neg = -1;
		(*str)++;
	}
	while (ft_isdigit(**str))
	{
		num += (num * 10) + ((**str) - '0');
		(*str)++;
	}
	printf("num %d\n", num);
	return (num * neg);
}
