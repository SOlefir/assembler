/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:46:02 by solefir           #+#    #+#             */
/*   Updated: 2019/10/15 00:23:06 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static _Bool	that_type(int type, int arg)
{
	if ((arg & type) == 0 || (arg & type) == type)
		return (1);
	return (0);
}

static int	check_arg(int type, char **instr)
{
	int	code;

	if ((**instr) == '%' && that_type(T_DIR, type))
		code = DIR_CODE;
	else if ((**instr) == 'r' && that_type(T_REG, type))
		code = REG_CODE;
	else if (((**instr) == LABEL_CHAR || ft_isdigit((int)(**instr))) &&
			that_type(T_IND, type))
		code = IND_CODE;
	else
		error_exit("Wrong args", 0);
	*instr += skip_whitespaces(++(*instruct));
	if ((**instr) != LABEL_CHAR || !ft_isdigit((int)(**instr)))
		error_exit("Wrong args", 0);
	return (code);
}

static int	get_argument(int **code, char **instr, int *types, char end_arg)
{
	int	end_arg;
	int	arg;

	arg = 0;
	*code = check_arg(types[0], instr)
	if (**instr == LABEL_CHAR && (*instr++))
		return (-1);
	arg = itoa_for_args(**instr, c); // сдвигает указатель
	if (c == SEPARATOR_CHAR && **instr == '\0')
		error_exit("нет сепар. символа");
	return (arg);
}

t_args		parse_code(char *instruct, t_op *op)
{
	int		i;
	int		count_arg;
	t_arg	*ret;
	char	c;

	i = -1;
	count_arg = op->arg;
	ret = (t_instr*)malloc(sizeof(t_instr));
	ret->count_arg = count_arg;
	ret->args = (int*)ft_memalloc(sizeof(int) * count_arg);
	instruct += ft_strlen(op->name_op) + skip_whitespaces(instruct);
	while (--count_arg >= 0)
	{
		instruct += skip_whitespaces(instruct);
		c = count_arg > 0 ? SEPARATOR_CHAR : '\0';
		if ((ret->args[++i] = get_argument(&ret, &instruct, op->arg_types[i], c)) < 0)
			ret->label = ft_strndub(instruct, (instruct - ft_strchr(instruct, c)));

	}
	ret->bytes_arg = size_code(ret->args);
	return (ret);
}
