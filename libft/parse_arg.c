/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 17:26:03 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 19:25:26 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		parse_arg(t_printf *global)
{
	t_flags flags;

	ft_bzero(&flags, sizeof(t_flags));
	find_flags(global, &flags);
	specifier(global, &flags);
}
