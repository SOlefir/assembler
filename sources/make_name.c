/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:01:13 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/10/18 21:42:06 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*make_name(char *name_champ)
{
	char	*name;
	int		i;
	int		c;
	int		m;

	printf("%s\n", name_champ);
	i = ft_strlen(name_champ) - 2;
	m = i;
	while (name_champ[m - 1] && name_champ[(m - 1)] != '/')
		m--;
	i = i - m;
	c = 0;
	name = (char*)ft_memalloc(sizeof(char) * i + COR_SIZE + 1);
	while (c < i)
	{
		name[c] = name_champ[m];
		c++;
		m++;
	}
	i = 0;
	while (i < COR_SIZE)
	{
		name[c] = COR[i];
		c++;
		i++;
	}
	printf("%s\n", name);
	return (name);
}
