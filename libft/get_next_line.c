/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:03:45 by solefir           #+#    #+#             */
/*   Updated: 2019/07/22 15:58:53 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		in_line(t_gnl *node, char **line)
{
	int		i;

	if (node->str == NULL)
		return (0);
	i = (node->end != NULL)
		? (int)(node->end - node->str)
		: (int)ft_strlen(node->str);
	if (!(*line = (char *)malloc((size_t)(i + 1))))
		return (-1);
	ft_strncpy(*line, node->str, (size_t)i);
	(*line)[i] = '\0';
	if (node->end != NULL && *(node->end + 1) != '\0')
		node->end = ft_strsub(node->str, (unsigned)i + 1,
											(size_t)(node->leng - i));
	else if (node->end != NULL && *(node->end + 1) == '\0')
		node->end = NULL;
	free(node->str);
	node->leng -= (i + 1);
	node->str = node->end;
	return (1);
}

static void		read_in_buf(const int fd, t_gnl *gnl)
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	int		i;

	while (gnl->end == NULL && (i = (int)read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (gnl->str == NULL)
			gnl->str = ft_strdup(buf);
		else
		{
			temp = gnl->str;
			gnl->str = ft_strjoin(gnl->str, buf);
			free(temp);
		}
		gnl->end = ft_strchr(gnl->str, '\n');
		gnl->leng += i;
	}
}

static t_gnl	*find_fd(t_gnl *head, int fd)
{
	while (head != NULL && head->fd != fd)
		head = head->next;
	return (head);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl = NULL;
	t_gnl			*temp;
	int				s;

	s = read(fd, 0, 0);
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (!(temp = find_fd(gnl, fd)))
	{
		if (!(temp = (t_gnl*)ft_memalloc(sizeof(t_gnl))))
			return (-1);
		temp->next = gnl;
		gnl = temp;
		temp->fd = fd;
		temp->end = NULL;
	}
	if (temp->str != NULL && (temp->end = ft_strchr(temp->str, '\n')))
		return (in_line(temp, line));
	read_in_buf(fd, temp);
	return (in_line(temp, line));
}
