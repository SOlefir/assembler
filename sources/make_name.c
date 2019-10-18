/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:01:13 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/10/18 15:29:07 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*make_name(char *name_champ)
{
	char	*name;
	int		i;
	int		c;

	i = ft_strlen(name_champ) - 2;
	c = 0;
	name = malloc(sizeof(char) * i + COR_SIZE);
	while (c < i)
	{
		name[c] = name_champ[c];
		c++;
	}
	i = 0;
	while (i < COR_SIZE)
	{
		name[c] = COR[i];
		c++;
		i++;
	}
	return (name);
}
