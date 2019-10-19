/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:46:02 by solefir           #+#    #+#             */
/*   Updated: 2019/10/19 03:17:51 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	that_type(int type, int arg)
{
	int	that;

	that = arg & type;
	printf("%d %d\n", that, type);
	if (that == type)
		return (1);
	return (0);
}

static int	check_arg(int type, char **instr)
{
	int	code;
	int i;

	code = 0;
	printf("{%s}\n", *instr);
	printf("%c\n", LABEL_CHAR);
	printf("%c\n", **instr);
	if ((**instr) == '\0')
		error_exit("Too few arguments", 1);
	else if ((**instr) == '%' && that_type(T_DIR, type))
		code = DIR_CODE;
	else if ((**instr) == 'r' && that_type(T_REG, type))
		code = REG_CODE;
	else if (that_type(T_IND, type) && (**instr == LABEL_CHAR ||
		ft_isdigit((int)**instr) || **instr == '-')) ///почему-то тут не заходит в тело ифа
		code = IND_CODE;
	else
		error_exit("Invalid argument type or invalid character", 1);
	(*instr)++;
	instr += skip_whitespaces(*instr);
	if ((**instr) != '-' && (**instr) != LABEL_CHAR &&
		!ft_isdigit((int)(**instr)))
	 	error_exit("Incorrect parameters passed", 1);
	return (code);
}

static int	get_arg(int *code, char **instr, int *types)
{
	int	arg;

	arg = 0;
	*code = check_arg(types[0], instr);
	// printf("not lbc: %c\n", **instr);
	if (**instr == LABEL_CHAR)
	{
		return (-1);
	}
	arg = atoi_for_args(instr); 
	if (*code == REG_CODE && (arg < 0 || arg > (1 + REG_NUMBER)))
		error_exit("Register number greater or less than permissible", 1);
	if (**instr == SEPARATOR_CHAR)
		(*instr)++;
	return (arg);
}

t_args		*parse_code(char *instr, t_op *op)
{
	int		i;
	int		code;
	int		count_arg;
	t_args	*ret;

	i = -1;
	code = 0;
	printf("opcode: %s, args: %d\n", op->name_op, op->count_args);
	count_arg = op->count_args + 1;
	ret = init_args((unsigned char)op->code_op - 1);
	instr += ft_strlen(op->name_op);
	instr += skip_whitespaces(instr);
	while (--count_arg > 0)
	{
		i++;
		ret->args[i] = get_arg(&code, &instr, &op->arg_types[i]);
		if (ret->args[i] == -1)
		{
			// printf("NOT LBC: %c\n", *instr);
		 	if (*instr == LABEL_CHAR)
		 	{
				ret->labels[i] = get_lbl_name(&instr);
				instr += skip_whitespaces(instr);
				// printf("LABEL [%s]\n", ret->labels[i]);
			}
		}
		instr += (*instr == SEPARATOR_CHAR) ? 1 : 0;
		ret->arg_types[i] = code;
		ret->coding_byte |=  code << (3 - i) * 2;
		instr += skip_whitespaces(instr);
		if (count_arg == 0 && *instr != '\0' &&
			*instr != COMMENT_CHAR && *instr != ALT_COMMENT_CHAR)
			error_exit("Too many arguments", 1);
	}
	printf("ret ok!\n");
	return (ret);
}
