/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:07:12 by solefir           #+#    #+#             */
/*   Updated: 2019/09/16 15:16:57 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_nc(char *str, char f)
{
	int		i;
	int		cmd;
	int		quotes;

	quotes = 0;
	cmd = ft_strlen(f == 'c' ? COMMENT_CMD_STRING : NAME_CMD_STRING);
	i = -1;
	while (++i < cmd)
	{
		ft_printf("tut\n");
		while (ft_iswhitespace(str[i]))
			i++;
		if (str[i] == 34 && str[i++] !='\0')
			quotes++;
		if (quotes == 2 && str[i] != '\0')
			ft_printf("skip_komment\n");
			// skip_comments(str[i]);
		if ((quotes == 0 || quotes == 2) && str[i] != '\0')
			ft_printf("quotes\n");
			// error_quonc(quotes);
	}
}
