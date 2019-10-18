/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_for_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:06:32 by solefir           #+#    #+#             */
/*   Updated: 2019/10/18 20:16:53 by solefir          ###   ########.fr       */
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
	printf("\n          ATOI     \n");
	(void)end;
	if (**str == '-')
	{
		neg = -1;
		(*str)++;
	}
	printf("%s\n", *str);
	while (ft_isdigit(**str))
	{
		num += num * 10 + (**str) - '0';
		(**str)++;
	}
	printf("NUM %d\n", num);
	printf("%s\n\n", *str);
	return (num * neg);
}
