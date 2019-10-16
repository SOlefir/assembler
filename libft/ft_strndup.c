/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:41:30 by solefir           #+#    #+#             */
/*   Updated: 2019/10/16 16:52:06 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strndup(const char *str, int n)
{
	char	*dup;

	if (!(dup = malloc(sizeof(char) * n + 1)))
		return (NULL);
	dup[n] = '\0';
	while (--n >= 0)
		dup[n] = str[n];
	return (dup);
}
