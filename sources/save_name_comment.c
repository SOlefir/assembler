/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_name_comment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:08:16 by solefir           #+#    #+#             */
/*   Updated: 2019/09/16 15:13:42 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	_Bool	comments(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		while (ft_iswhitespace(str[i]))
			i++;
		if (str[i] == '\0' || str[i] == '#')
			return (1);
	}
	return (0);	
}

static	_Bool	is_comment(char *str)
{
	int i;

	i = -1;
	if (ft_strcmp(str, COMMENT_CMD_STRING) == 0)
		return (0);
	check_nc(str, 'c');
	return (1);
}

static	_Bool	is_name(char *str)
{
	int i;

	i = -1;
	if (ft_strcmp(str, NAME_CMD_STRING) == 0)
		return (0);
	ft_printf("tut\n");
	check_nc(str, 'n');
	return (1);
}

static void		*get_nc(char **binary, char	**str, int size)
{
	int 	i;
	int		j;

	i = -1;
	j = 0;
	while (++i <= size)
		if (binary[i])
			str[i] = binary[j++];
		else
			str[i] = 0;
	free(*binary);
	return (str);
}

t_header		*save_nc(int fd)
{
	t_header	*head;
	char		*line;
	int 		i[2];

	line = NULL;
	head = (t_header*)ft_memalloc(sizeof(t_header));
	i[0] = 0;
	i[1] = 0;
	while (get_next_line(fd, &line) > 0)
	{
		g_str_n++;
		ft_printf("tut\n");
		/*if (comments(&line))
			continue ;*/
		if (i[0] += is_name(line))
		{
			if (i[0] == 1)
				get_nc(make_binary(&line), &head->prog_name, PROG_NAME_LENGTH + 1);
			else 
				ft_printf("error1\n");// error(&line);
		}
		ft_printf("tut\n");
		if (i[1] += is_comment(line))
		{
			if (i[1] == 1)
				get_nc(make_binary(&line), &head->comment, PROG_NAME_LENGTH + 1);
			else 
				ft_printf("error2\n");// error(&line);
		}
		ft_printf("tut\n");
	}
	if (!i[0] && !i[1])
		ft_printf("error3\n");// error("no comment & name");
	ft_printf("%s\n", head->comment);
	return (head);
}
