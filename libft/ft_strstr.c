/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 21:55:47 by dquitzon          #+#    #+#             */
/*   Updated: 2019/08/07 14:18:30 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (needle == NULL || needle[0] == '\0')
		return ((char *)haystack);
	if (haystack == NULL || haystack[0] == '\0')
		return (NULL);
	while (haystack[i] != '\0')
	{
		k = 0;
		while (haystack[i + k] && needle[k] &&
				haystack[i + k] == needle[k])
			k++;
		if (needle[k] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
