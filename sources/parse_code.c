/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:46:02 by solefir           #+#    #+#             */
/*   Updated: 2019/10/18 18:50:16 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

// static int		size_code_args(int	type, t_op *op)
// {
// 	if (type == T_DIR)
// 	{
// 		if (op->code_op > 9 || op->code_op == 13 || op->code_op == 16)
// 			return (DIR_SIZE);
// 		else
// 			return (IND_SIZE);
// 	}
// 	if (type == T_REG)
// 		return (REG_SIZE);
// 	if (type == T_IND)
// 		return (IND_SIZE);
// 	return (0);
// }

// static void		last_check_args(char *instr, int type)
// {
// 	if (code == REG_CODE && *instr == '-')
// }

static int	that_type(int type, int arg)
{
	int	that;

	that = arg & type;
	printf("%d & %d\n", arg, type);
	printf("that = %d\n", that);
	if (that == type)
		return (1);
	return (0);
}

static int	check_arg(int type, char **instr)
{
	int	code;
	int i;

	code = 0;
	// printf("c->> %c\n", **instr);
	if ((**instr) == '\0')
		error_exit("Too few arguments", 0);
	else if ((**instr) == '%' && (i = that_type(T_DIR, type)) && printf("tut--->%d\n", i))
		code = DIR_CODE;
	else if ((**instr) == 'r' && (i = that_type(T_REG, type)))
		code = REG_CODE;
	else if (((**instr) == LABEL_CHAR || ft_isdigit((int)(**instr)) || 
		(**instr) == '-') && (i = that_type(T_IND, type)))
		code = IND_CODE;
	else
		error_exit("Invalid argument type or invalid character", 0);
	(*instr)++;
	//last_check_args(*instr, code);
	printf("instr(check)-> [%s]\n", *instr);
	if ((**instr) != '-' && (**instr) != LABEL_CHAR &&
		!ft_isdigit((int)(**instr)))
	 	error_exit("Incorrect parameters passed", 0);
	// printf("instr(check)-> [%s]\n", *instr);
	// printf("code: %d\n", code);
	return (code);
}

static int	get_arg(int *code, char **instr, int *types, char end_arg)
{
	int	arg;

	arg = 0;
	*code = check_arg(types[0], instr);
	if (**instr == LABEL_CHAR)// && *(++(*instr)) != '\0')
		return (-1);
	arg = atoi_for_args(instr, end_arg); // сдвигает указатель
	if (*code == REG_CODE && (arg < 0 || arg > REG_NUMBER))
		error_exit("Register number greater or less than permissible", 0);
	// if ((end_arg == SEPARATOR_CHAR && **instr != end_arg) ||
	// 	(end_arg == '\0' && **instr != '\0'))
	// 	error_exit("неправильное кол-во аргументов", 0);
	// printf("%d\n", arg);
	// printf("end_arg: %c\n", end_arg);
	// printf("instr(get)---> [%s]\n", *instr);
	if (**instr == SEPARATOR_CHAR)
		(*instr)++;
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
	code = 0;
	//printf("opcode: %s, args: %d\n", op->name_op, op->count_args);
	count_arg = op->count_args;
	ret = init_args((unsigned char)op->code_op - 1);//count_arg);
	instr += ft_strlen(op->name_op) + 1 + skip_whitespaces(instr);
	while (count_arg > 0)
	{
		//printf("instr(parse)-> [%s]\n", instr);
		c = (count_arg == 1) ? '\0' : SEPARATOR_CHAR;
		if ((ret->args[i] = get_arg(&code, &instr, &op->arg_types[i], c)) < 0)
		{
			ret->labels[i] = ft_strndup((instr + 1), (ft_strchr(instr, c) - instr - 1));
			instr += ft_strlen(ret->labels[i]) + 1;	
			if (*instr == SEPARATOR_CHAR)
				(instr)++;
		}
		// printf("lalbel %s\n", ret->labels[i]);
		// printf("arg = %d\n", ret->args[i]);
		//ret->size_arg += size_code_args(code, op);
		ret->arg_types[i] = code;
		ret->coding_byte |=  code << (3 - i) * 2;
		count_arg--;
		i++;
		instr += skip_whitespaces(instr);
		if (count_arg == 0 && *instr != '\0' &&
			*instr != COMMENT_CHAR && *instr != ALT_COMMENT_CHAR)
			error_exit("Too many arguments", 0);
	}
	return (ret);
}
