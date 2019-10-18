/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:46:02 by solefir           #+#    #+#             */
/*   Updated: 2019/10/18 22:44:34 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

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
	int	code;
	int i;

	code = 0;
	if ((**instr) == '\0')
		error_exit("Too few arguments", 1);
	else if ((**instr) == '%' && (i = that_type(T_DIR, type)))
		code = DIR_CODE;
	else if ((**instr) == 'r' && (i = that_type(T_REG, type)))
		code = REG_CODE;
	else if (((**instr) == LABEL_CHAR || ft_isdigit((int)(**instr)) || 
		(**instr) == '-') && (i = that_type(T_IND, type)))
		code = IND_CODE;
	else
		error_exit("Invalid argument type or invalid character", 1);
	(*instr)++;
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
	if (**instr == LABEL_CHAR)
		return (0);
	arg = atoi_for_args(instr); 
	if (*code == REG_CODE && (arg < 0 || arg > (1 + REG_NUMBER)))
		error_exit("Register number greater or less than permissible", 1);
	if (**instr == SEPARATOR_CHAR)
		(*instr)++;
	printf("%d\n", arg);
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
	count_arg = op->count_args;
	ret = init_args((unsigned char)op->code_op - 1);
	instr += ft_strlen(op->name_op);
	printf("parse str 1[%s]\n", instr);
	instr += skip_whitespaces(instr);
	printf("parse str 2[%s]\n", instr);
	while (count_arg > 0)
	{
		c = (count_arg == 1) ? '\0' : SEPARATOR_CHAR;
		if (!(ret->args[i] = get_arg(&code, &instr, &op->arg_types[i])) && *instr == LABEL_CHAR)
		{
			printf("parse str dup[%s]\n", instr);
			ret->labels[i] = ft_strndup((instr + 1), (ft_strchr(instr, c) - instr - 1));
			printf("-->%s\n", ret->labels[i]);
			instr += ft_strlen(ret->labels[i]) + 1;	
			if (*instr == SEPARATOR_CHAR)
				(instr)++;
		}
		ret->arg_types[i] = code;
		ret->coding_byte |=  code << (3 - i) * 2;
		count_arg--;
		i++;
		instr += skip_whitespaces(instr);
		printf("parse str 3[%s]\n", instr);
		if (count_arg == 0 && *instr != '\0' &&
			*instr != COMMENT_CHAR && *instr != ALT_COMMENT_CHAR)
			error_exit("Too many arguments", 1);
	}
	return (ret);
}
