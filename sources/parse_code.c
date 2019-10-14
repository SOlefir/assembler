
static int	*get_argument(char *instr, int *args, char c)
{
	int	i;
	int	j;
	int	ret;

	i = -1;
	j = 0;
	while (instr[++i] != c || instr[i] != '\0')
	{
		if (args[j] == )
	}
	if (c = SEPARATOR_CHAR && instr[i] == '\0')
		errors("нет сепар. символа");
	return (ret);
}


t_instr		parse_code(char *instruct, t_op *op)
{
	t_arg	*ret;
	int		i;
	int		count_arg;
	char	c;

	i = 0;
	count_arg = op->arg;
	ret = (t_instr*)ft_memalloc(sizeof(t_instr));
	ret->count_arg = count_arg;
	ret->code_op = op->code_op;
	ret->args = (int*)ft_memalloc(sizeof(int) * count_arg);
	while (--count_arg >= 0)
	{
		c = count_arg > 0 ? SEPARATOR_CHAR : '\0';
		ret->args[i] = get_argument(instruct, op->arg_types[i], c);
		i++;
	}
	ret->bytes = size_code(ret->args);
	return (ret);
}
