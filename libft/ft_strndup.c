/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:41:30 by solefir           #+#    #+#             */
/*   Updated: 2019/09/29 20:13:32 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strdup(const char *str, uint n)
{
	size_t	i;
	char	*dup;

	if (!dup = malloc(sizeof(char) * n + 1))
		return (NULL);
	dup[n] = '\0'
	while (--n >= 0)
		dup[n] = str[n];
	return (dup);
}
