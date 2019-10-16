/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:46:02 by solefir           #+#    #+#             */
/*   Updated: 2019/10/16 17:06:55 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "stdio.h"

static int		size_code_args(int	type, t_op *op)
{
	if (type == T_DIR)
	{
		if (op->code_op > 9 || op->code_op == 13 || op->code_op == 16)
			return (DIR_SIZE);
		else
			return (IND_SIZE);
	}
	if (type == T_REG)
		return (REG_SIZE);
	if (type == T_IND)
		return (IND_SIZE);
	return (0);
}

static _Bool	that_type(int type, int arg)
{
	if ((arg & type) == 0 || (arg & type) == type)
		return (1);
	return (0);
}

static int	check_arg(int type, char **instr)
{
	int	code;

	code = 0;
	if ((**instr) == '%' && that_type(T_DIR, type))
		code = DIR_CODE;
	else if ((**instr) == 'r' && that_type(T_REG, type))
		code = REG_CODE;
	else if (((**instr) == LABEL_CHAR || ft_isdigit((int)(**instr))) &&
			that_type(T_IND, type))
		code = IND_CODE;
	else
		error_exit("Wrong args", 0);
	*instr += skip_whitespaces(++(*instr));
	if ((**instr) != LABEL_CHAR || !ft_isdigit((int)(**instr)))
		error_exit("Wrong args", 0);
	return (code);
}

static int	get_arg(int *code, char **instr, int *types, char end_arg)
{
	int	arg;

	arg = 0;
	*code = check_arg(types[0], instr);
	if (**instr == LABEL_CHAR && (*instr++))
		return (-1);
	arg = atoi_for_args(instr, end_arg); // сдвигает указатель
	if (end_arg == SEPARATOR_CHAR && **instr == '\0')
		error_exit("нет сепар. символа", 0);
	return (arg);
}

t_args		*parse_code(char *instr, t_op *op)
{
	int		i;
	char	c;
	int		code;
	int		count_arg;
	t_args	*ret;

	i = 0;
	c = '\0';
	code = 0;
	count_arg = op->arg;
	ret = init_args(count_arg);
	instr += ft_strlen(op->name_op) + skip_whitespaces(instr);
	while (count_arg)
	{
		instr += skip_whitespaces(instr);
		c = (count_arg == 1) ? '\0' : SEPARATOR_CHAR;
		if ((ret->args[i] = get_arg(&code, &instr, &op->arg_types[i], c)) < 0)
			ret->label = ft_strndup(instr, (ft_strchr(instr, c)) - instr);
		ret->size_arg += size_code_args(code, op);
		ret->types |=  code << (2 * count_arg);
		count_arg--;
		i++;
	}
	return (ret);
}
