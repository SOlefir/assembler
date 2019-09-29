/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:23:43 by dquitzon          #+#    #+#             */
/*   Updated: 2019/07/21 16:50:57 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_atoi(const char *str)
{
	int			neg;
	size_t		i;
	long		nmb;
	long		temp;
	int			k;

	i = 0;
	nmb = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	neg = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (!(k = 0) && (int)ft_isdigit(str[i]))
	{
		if (((temp = nmb) == nmb) && ((nmb += str[i++] - '0') < 0))
			return ((neg > 0) ? -1 : 0);
		while (++k < 10)
		{
			nmb += temp;
			if (nmb < 0)
				return ((neg > 0) ? -1 : 0);
		}
	}
	return (((int)nmb) * neg);
}
