/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 23:35:22 by solefir           #+#    #+#             */
/*   Updated: 2019/09/30 00:24:35 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*encode_instruct(char *instruct, t_op *op)
{
	int		i;
	char	*code;

	code = ft_atoi(op.code_op);
	i = ft_strlen(op.name);
	while (instruct[++i] != '\0')
	{
		i += skip_whitespaces(instruct[i]);
		if (instruct[i] == DIRECT_CHAR)
			code += T_DIR;
		else if (instruct[i] == 'r')
			code += T_REG;
		else if (instruct[i] == ft_isdigit(instruct[i]) || 
				instruct[i] == LABEL_CHAR)
			code += T_IND
		
	}
}