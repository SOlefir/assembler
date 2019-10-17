/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:17:42 by solefir           #+#    #+#             */
/*   Updated: 2019/10/17 20:28:06 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void		check_args(char *instr, int count_args)
{
	if (*instr != SEPARATOR_CAR && *instr != '\0')
		error_exit("Lecsic error, maybe need insert SEPARATOR_CAR", 0);
	if (count_args > op->count_args ||
		(*instr == '\0' && count_args != op->count_args))
		error_exit("Have no separator or wrong count of args", 0);

}

static _Bool	that_type(int type, int arg)
{
	if ((arg & type) == 0 || (arg & type) == type)
		return (1);
	return (0);
}

static int			get_type(int type, char **instr)
{
	// printf("c->> %c\n", **instr);
	if ((**instr) == '%' && that_type(T_DIR, type))
		return (DIR_CODE);
	else if ((**instr) == 'r' && that_type(T_REG, type))
		return (REG_CODE);
	else if (((**instr) == LABEL_CHAR || ft_isdigit((int)(**instr))) &&
			that_type(T_IND, type))
		return (IND_CODE);
	else
		error_exit("Wrong 1args", 0);
	(*instr)++;
	// printf("instr(check)-> [%s]\n", *instr);
	// printf("code: %d\n", code);
	return (0);
}

t_args		*parse_code(char *instr, t_op *op)
{
	t_args	*ret;
	char	end_arg;
	int		mov;
	int		j;

	ret = init_args(op->count_args);
	ret->op_code = (unsigned char)op->code_op;
	instr += ft_strlen(op->name_op) + 1;
	j = 0;
	mov = 3;
	while (*instr != '\0')
	{
		instr += skip_whitespaces(instr);
		ret->arg_types[j] = get_type(op->arg_types[j], instr);
		if (instr == LABEL_CHAR)
			ret->labels[j] = ft_strndup(++instr, SEPARATOR_CHAR);//get lbl name
		instr += (instr + 1]) == '-' ? 0 : 1;
		if (ft_isdigit((int)*(++instr)))
			ret->args[j] = atoi_for_args(&instr, c);
		check_args(instr, j);
		ret->coding_byte[j] |= ret->arg_types[j] << (2 * mov--);
		j++;
	}
}
