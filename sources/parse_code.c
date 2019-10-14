/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:46:02 by solefir           #+#    #+#             */
/*   Updated: 2019/10/15 01:27:27 by solefir          ###   ########.fr       */
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

static int	get_arg(int **code, char **instr, int *types, char end_arg)
{
	int	end_arg;
	int	arg;

	arg = 0;
	*code = check_arg(types[0], instr);
	if (**instr == LABEL_CHAR && (*instr++))
		return (-1);
	arg = itoa_for_args(**instr, c); // сдвигает указатель
	if (c == SEPARATOR_CHAR && **instr == '\0')
		error_exit("нет сепар. символа");
	return (arg);
}

t_args		parse_code(char *instr, t_op *op)
{
	int		i;
	int		code;
	int		count_arg;
	t_arg	*ret;
	char	c;

	i = -1;
	code = 0;
	count_arg = op->arg;
	ret = (t_arg*)ft_memalloc(sizeof(t_arg));
	ret->count_arg = count_arg;
	ret->args = (int*)ft_memalloc(sizeof(int) * count_arg);
	instr += ft_strlen(op->name_op) + skip_whitespaces(instr);
	while (count_arg)
	{
		instr += skip_whitespaces(instr);
		c = (count_arg == 1) ? '\0' : SEPARATOR_CHAR;
		if ((ret->args[++i] = get_arg(&code, &instr, op->arg_types[i], c)) < 0)
			ret->label = ft_strndub(instr, (instr - ft_strchr(instr, c)));
		ret->types |=  code << (2 * count_arg);
		count_arg--;
	}
	ret->size = size_code(ret->args); // размер аргументов в сумме
	return (ret);
}
