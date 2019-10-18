/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:01:13 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/10/16 22:19:15 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*make_name(char *name_champ)
{
	char	*name;
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (name_champ[i] != '\0')
		i++;
	while (name_champ[i] != '.')
		i--;
	if (name_champ[(i + 1)] != 's')
		return ("false");
	// name = malloc(sizeof(char) * i + COR_SIZE);
	name = malloc(sizeof(char) * i + PROG_NAME_LENGTH);
	while (c < i)
	{
		name[c] = name_champ[c];
		c++;
	}
	i = 0;
	// while (i < COR_SIZE)
	while (i < PROG_NAME_LENGTH)
	{
		// name[c] = COR[i];
		name[c] = 0;
		c++;
		i++;
	}
	return (name);
}
