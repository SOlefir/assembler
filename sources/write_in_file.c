/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_in_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 22:18:08 by solefir           #+#    #+#             */
/*   Updated: 2019/10/18 19:41:52 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	write_uints(int fd, unsigned int out, _Bool size)
{
	int		j;
	char	*to_out;
	char	*now;

	to_out = malloc(sizeof(char) * ((size ? 2 : 4)));
	now = (char *)(&out);
	now += ((size) ? 1 : 3);
	j = 0;
	while (j++ < ((size) ? 2 : 4))
	{
		to_out[j - 1] = *now;
		now--;
	}
	write(fd, to_out, (size) ? 2 : 4);
	free(to_out);
}

void	write_in_file(char *prog_name, t_holder *holder)
{
	int			fd;
	t_instruct	*code_part;

	fd = open(prog_name, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	//printf("%d\n", holder->bytes_count);
	write_uints(fd, holder->header->magic, 0);
	write(fd, holder->header->prog_name, PROG_NAME_LENGTH);
	write(fd, "\0\0\0\0", 4);
	write_uints(fd, holder->bytes_count, 0);
	write(fd, holder->header->comment, COMMENT_LENGTH);
	write(fd, "\0\0\0\0", 4);
	code_part = holder->code;
	while (code_part) 
	{
		// printf("PRINTING > %d!\n", code_part->size); 
		write(fd, code_part->str, code_part->size);
		code_part = code_part->next;
	}
	// printf("%s\n", holder->code->code);
	// printf("HERE\n");
	// while (holder->code->next != NULL)
	// {
	// 	printf("WHAT\n");
	// 	write(fd, holder->code->code, holder->code->size);
	// 	printf("KEK\n");
	// 	holder->code = holder->code->next;
	// 	printf("LOL\n");
	// }
	// printf("HERE\n");
	// write(fd, holder->code->code, holder->code->size);
	// printf("HERE\n");
}