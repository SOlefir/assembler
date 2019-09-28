/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_from_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:40:11 by solefir           #+#    #+#             */
/*   Updated: 2019/09/28 20:13:58 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static t_list		*ft_lstnewsimple(char *str)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->content = str;
	list->next = NULL;
	return (list);
}

static void			ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*now;

	if (alst == NULL || new == NULL)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		return;
	}
	now = *alst;
	while (now->next)
		now = now->next;
	now->next = new;
}

char				*collapse_list(t_list **head, size_t n)
{
	t_list	*now;
	t_list	*next;
	char	*ret;
	size_t	total;

	now = *head;
	total = ft_strlen((char *)now->content);
	while ((now = now->next))
			total += ((now->next) ? ft_strlen((char *)now->content) : n) + 1;
	ret = (char *)ft_memalloc(sizeof(char) * (total + 1));
	now = *head;
	while (now)
	{
		next = now->next;
		ft_strncat(ret, now->content, (next) ? SIZE_MAX : n);
		if (next)
		{
			ft_strcat(ret, "\n");
			ft_strdel((char**)&(now->content));
		}
		free(now);
		now = next;
	}
	*head = NULL;
	return (ret);
}

char				*extract_from_quotes(int fd, char quote, char **str)
{
	t_list	*head;
	char	*end;

	head = NULL;
	head = ft_lstnewsimple(*str);
	while (!(end = ft_strchr(*str, quote)) && get_next_line(fd, str) > 0)
	{
		g_str_n++;
		ft_lstappend(&head, ft_lstnewsimple(*str));
	}
	if (!end)
		error_exit("quote is not closed", 0);
	return (collapse_list(&head, end - *str));
}