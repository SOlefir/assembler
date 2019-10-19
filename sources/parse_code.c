/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:46:02 by solefir           #+#    #+#             */
/*   Updated: 2019/10/19 21:08:08 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdio.h> //

static int	that_type(int type, int arg)
{
	int	that;

	that = arg & type;
	if (that == type)
		return (1);
	return (0);
}

static int	check_arg(int type, char **instr)
{
	if ((**instr) == '\0')
		error_exit("Too few arguments", 1);
	else if ((**instr) == '%' && that_type(T_DIR, type))
		return (DIR_CODE);
	else if ((**instr) == 'r' && that_type(T_REG, type))
		return (REG_CODE);
	else if (that_type(T_IND, type) && (**instr == LABEL_CHAR ||
		ft_isdigit((int)**instr) || **instr == '-'))
		return (IND_CODE);
	else 
		errors_in_args(*instr);
	return (0);
}

static int	get_arg(int *code, char **instr, int *types)
{
	int	arg;

	arg = 0;
	*code = check_arg(types[0], instr);
	// if (*code == IND_CODE)
	// 	printf("%d str%d %s\n", *code, g_str_n, *instr);
	(*instr) += *code == IND_CODE ? 0 : 1;//(**instr == LABEL_CHAR || **instr == '-') ? 0 : 1;
	if (**instr == LABEL_CHAR)
		return (-1);
	*instr += skip_whitespaces(*instr);
	if ((**instr) != '-' && !ft_isdigit((int)(**instr)))
		error_exit("Incorrect parameters passed", 1);
	if (*code == IND_CODE)
		printf("===%s\n", *instr);
	arg = atoi_for_args(instr);
	if (*code == IND_CODE)
		printf("arg %d\n", arg);
	if (*code == REG_CODE && (arg < 0 || arg > (1 + REG_NUMBER)))
		error_exit("Register number greater or less than permissible", 1);
	//if (**instr == SEPARATOR_CHAR)
	//	(*instr)++;
	return (arg);
}

static void	validation_args(char **instr, int count_arg, _Bool first)
{
	int	i;

	printf("---->>%s\n", *instr);
	if (first)
	{
		if (**instr == SEPARATOR_CHAR)
			error_exit("The separator character must be only between arguments", 1);
	}
	else
	{
		i = skip_whitespaces(*instr);
		*instr += i;
		if (count_arg <= 1 && (**instr) != '\0' &&
		(**instr) != COMMENT_CHAR && (**instr) != ALT_COMMENT_CHAR)
			error_exit("Too many arguments for this operation or excess char", 1);
		*instr -= i;
		if ((count_arg > 1 && **instr != SEPARATOR_CHAR) ||
			(count_arg == 1 && **instr == SEPARATOR_CHAR))
			error_exit("Inappropriate use the separator character", 1);
	}
	*instr += (**instr == SEPARATOR_CHAR) ? 1 : 0;
	*instr += skip_whitespaces(*instr);
}

t_args		*parse_code(char *instr, t_op *op)
{
	int		i;
	int		code;
	int		count_arg;
	t_args	*ret;

	i = -1;
	code = 0;
	count_arg = op->count_args + 1;
	ret = init_args((unsigned char)op->code_op - 1);
	instr += ft_strlen(op->name_op);
	printf("INSTR {%s}\n", instr);
	validation_args(&instr, count_arg, 1);
	// instr += skip_whitespaces(instr);
	printf("INSTR {%s}\n", instr);
	while (--count_arg > 0 && (++i) >= 0)
	{
		printf("to GET ARGS [%s]\n", instr);
		ret->args[i] = get_arg(&code, &instr, &op->arg_types[i]);
		if (ret->args[i] == -1 && *instr == LABEL_CHAR)
		{
			ret->labels[i] = get_lbl_name(&instr);
			//instr += (*instr == SEPARATOR_CHAR) ? 1 : 0;
		}
		//instr += skip_whitespaces(instr);
		validation_args(&instr, count_arg, 0);
		ret->arg_types[i] = code;
		ret->coding_byte |= code << (3 - i) * 2;
	}
	return (ret);
}
