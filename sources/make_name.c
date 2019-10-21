/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:01:13 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/10/21 18:13:32 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
// #include <stdio.h>

// char	*make_name(char *name_champ)
// {
// 	char	*name;
// 	int		leng;
// 	int		cor_size;
// 	int		i;

// 	cor_size = 4 + 1;
// 	printf("%s\n", name_champ);
// 	leng = ft_strlen(name_champ) - 2;
// 	name = (char*)ft_memalloc(leng + cor_size);
// 	cor_size++;
// 	i = leng + cor_size;
// 	name[i] = '\0';
// 	while (--i)
// 	{
// 		if ((--cor_size) > 0)
// 		{
// 			name[i] = COR[cor_size];
// 			continue ;
// 		}
// 		if ((--leng))
// 			name[i] = name_champ[leng];
// 		printf("[%c]", name_champ[leng]);
// 		printf("%c", name[i]);
// 	}
// 	printf("\n->%s\n", name);
// 	return (name);
// }

char	*make_name(char *name_champ)
{
	char	*name;
	int		i;
	int		c;
	int		m;

	i = ft_strlen(name_champ) - 2;
	m = i;
	while (name_champ[m - 1] && name_champ[(m - 1)] != '/')
		m--;
	i = i - m;
	c = -1;
	name = (char*)ft_memalloc(sizeof(char) * i + COR_SIZE + 1);
	while (++c < i)
	{
		name[c] = name_champ[m];
		m++;
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
