/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_instruction_code.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:18:01 by solefir           #+#    #+#             */
/*   Updated: 2019/09/29 20:30:57 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	save_instruction_code(char *instruct, t_holder **holder, char *lable)
{

	if (lable != NULL)
		holder->lables = init_lables(lable);

	1. если есть метка, то сохранить ее.
	2. 
}
