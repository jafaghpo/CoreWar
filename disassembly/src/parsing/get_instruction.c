/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:40:06 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/08 19:46:55 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

static int		get_octal_args(char *line, int size, int opcode)
{
	static int	(*octal_arg[3])() = {get_register, get_direct, get_indirect};
	int			octal;
	int			id;
	int			i;

	g_bin.i += 2;
	octal = g_bin.data[g_bin.i - 1];
	i = 0;
	while (i < g_op[opcode].nb_args)
	{
		id = (octal >> (6 - 2 * i)) & IND_CODE;
		if (id < REG_CODE || id > IND_CODE)
			return (print_error(BAD_ARGUMENT, g_bin.data[g_bin.i], g_bin.i));
		size += octal_arg[id - 1](line, size, opcode);
		if (i + 1 < g_op[opcode].nb_args)
			size += ft_sprintf(line + size, "%-4s", ",");
		i++;
	}
	return (size);
}

static int		get_regular_args(char *line, int size, int opcode)
{
	static int	(*get_arg[4])() = {get_register, get_direct, 0, get_indirect};
	int			i;
	int			id;

	i = 0;
	g_bin.i += 1;
	while (i < g_op[opcode].nb_args)
	{
		id = g_op[opcode].args[i];
		size += get_arg[id - 1](line, size, opcode);
		if (i + 1 < g_op[opcode].nb_args)
			size += ft_sprintf(line + size, "%-4s", ",");
		i++;
	}
	return (size);
}

static int		get_arguments(char *line, int opcode)
{
	int			size;

	if (opcode <= 0 || opcode >= OP_NB)
	{
		free(line);
		return (print_error(UNKNOWN_INST, opcode, g_bin.i));
	}
	size = ft_sprintf(line, "%-10s", g_op[opcode].inst);
	if (g_op[opcode].octal && !(size = get_octal_args(line, size, opcode)))
	{
		free(line);
		return (0);
	}
	else if (!g_op[opcode].octal)
		size = get_regular_args(line, size, opcode);
	if (g_asm.i + size > g_asm.size)
	{
		g_asm.size += BUFF_SIZE;
		if (!(g_asm.data = realloc(g_asm.data, g_asm.size)))
			return (print_error(strerror(errno)));
	}
	size += ft_sprintf(line + size, "\n");
	g_asm.i += ft_sprintf((char*)g_asm.data + g_asm.i, "%s", line);
	return (1);
}

int				get_inst(t_visual *win, t_tab *tab)
{
	char		*line;
	int			opcode;
	int			size;
	int			tmp;

	if (!(line = malloc(sizeof(*line) * LINE_LEN)))
		return (print_error(strerror(errno)));
	while (g_bin.i < g_bin.size)
	{
		tmp = g_bin.i;
		ft_memset((void*)line, 0, LINE_LEN);
		opcode = g_bin.data[g_bin.i];
		if (!get_arguments(line, opcode))
			return (0);
		if (g_option & VISUAL_FLAG)
			store_line(win, tab, (t_tab){ft_strdup(line), tmp, g_bin.i - tmp});
	}
	free(line);
	return (1);
}
