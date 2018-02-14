/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 21:50:51 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/29 15:10:51 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

char	*g_buf = NULL;
int		g_i = 0;

static int		octal_args(t_file *file, t_uint8 octal, int size, int nb_args)
{
	int		tmp;

	tmp = file->cursor - 1;
	if (!first_arg(file, octal, size))
		return (0);
	if (nb_args > 1)
	{
		display_separator(file, ",\t", tmp, file->cursor - tmp);
		if (!second_arg(file, octal, size))
			return (0);
	}
	if (nb_args > 2)
	{
		display_separator(file, ",\t", tmp, file->cursor - tmp);
		if (!third_arg(file, octal, size))
			return (0);
	}
	display_separator(file, "\n", tmp, file->cursor - tmp);
	return (1);
}

static void		no_octal_args(t_file *file, t_uint8 opcode)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = file->cursor;
	while (i < op_tab[opcode].nb_args)
	{
		if (op_tab[opcode].args[i] == T_REG)
			display_integer(file, "r%d", file->prog[file->cursor++]);
		else if (op_tab[opcode].args[i] == T_IND)
			short_arg(file, 0);
		else if (op_tab[opcode].args[i] == T_DIR && op_tab[opcode].size)
			short_arg(file, 1);
		else if (op_tab[opcode].args[i] == T_DIR && !op_tab[opcode].size)
			int_arg(file);
		if (i + 1 < op_tab[opcode].nb_args)
			display_separator(file, ",\t", tmp, file->cursor - tmp);
		i++;
	}
	display_separator(file, "\n", tmp, file->cursor - tmp);
}

static int		parse_inst(t_file *file)
{
	int		opcode;

	file->cursor = HEADER_SIZE;
	while (file->cursor < file->prog_size)
	{
		opcode = file->prog[file->cursor];
		if (opcode > 0 && opcode < 17)
			display_inst(file, opcode);
		else
			return (print_error(ERROR_INST));
		if (op_tab[opcode].octal)
		{
			if (!octal_args(file, file->prog[++file->cursor],
				op_tab[opcode].size, op_tab[opcode].nb_args))
				return (0);
		}
		else
			no_octal_args(file, opcode);
		file->cursor++;
	}
	return (1);
}

int				parse_file(t_file *file)
{
	int		fd;

	if ((fd = open(file->path, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
		return (print_error(NULL));
	if (!g_buf && !(g_buf = ft_memalloc(sizeof(char) * BSIZE * 4)))
		return (print_error(NULL));
	if (file->win.flag)
		win_setup(file);
	display_header(file);
	if (!parse_inst(file))
	{
		close(fd);
		return (0);
	}
	write(fd, g_buf, g_i);
	close(fd);
	return (1);
}
