/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 01:11:56 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/01 19:53:10 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_register(char **line, t_inst *inst)
{
	char	*str;
	int		reg;
	int		i;

	reg = 0;
	i = 0;
	str = *line;
	if (g_op[inst->data[0]].octal)
		inst->data[1] |= REG_CODE << (6 - 2 * inst->args);
	while (ft_isdigit(str[++i]))
		reg = reg * 10 + str[i] - '0';
	str += i;
	ft_delspace(&str);
	if (reg > REG_NUMBER || reg < 1)
		return (0);
	if ((*str != SEPARATOR_CHAR && *str != COMMENT_CHAR) && *str)
		return (0);
	inst->data[inst->size++] = (char)reg;
	return (1);
}

static int	get_direct(char **line, t_label *label, t_inst *inst)
{
	t_tmplb	tmp;
	int		n;
	int		error;

	error = 0;
	(*line)++;
	if (g_op[inst->data[0]].octal)
		inst->data[1] |= DIR_CODE << (6 - 2 * inst->args);
	n = eval_expr(*line, label, &error, g_bin.i - HEADER_LEN);
	if (error == 1)
		return (0);
	else if (error == 2)
	{
		tmp = (t_tmplb){*line, inst->size, g_op[inst->data[0]].size, 0, 0};
		label->tmp = add_tmp_label(label->tmp, tmp);
		inst->size += 2 + (!g_op[inst->data[0]].size);
		return (1);
	}
	store_argument(inst, n, g_op[inst->data[0]].size);
	return (1);
}

static int	get_indirect(char **line, t_label *label, t_inst *inst)
{
	t_tmplb	tmp;
	int		n;
	int		error;

	error = 0;
	if (g_op[inst->data[0]].octal)
		inst->data[1] |= IND_CODE << (6 - 2 * inst->args);
	n = eval_expr(*line, label, &error, g_bin.i - HEADER_LEN);
	if (error == 1)
		return (0);
	else if (error == 2)
	{
		tmp = (t_tmplb){*line, inst->size, 1, 0, 0};
		label->tmp = add_tmp_label(label->tmp, tmp);
		inst->size += 2;
		return (1);
	}
	store_argument(inst, n, 1);
	return (1);
}

int			parse_arguments(char *line, t_label *label, t_inst *inst)
{
	while (*line && inst->args != MAX_ARGS_NUMBER && *line != COMMENT_CHAR)
	{
		if (*line == 'r')
		{
			if (!(g_op[(int)inst->data[0]].args[inst->args] & T_REG)
			|| !get_register(&line, inst))
				return (print_error(REGISTER_ARG, line));
		}
		else if (*line == DIRECT_CHAR)
		{
			if (!(g_op[(int)inst->data[0]].args[inst->args] & T_DIR)
			|| !get_direct(&line, label, inst))
				return (print_error(DIRECT_ARG, line));
		}
		else
		{
			if (!(g_op[(int)inst->data[0]].args[inst->args] & T_IND)
			|| !get_indirect(&line, label, inst))
				return (print_error(INDIRECT_ARG, line));
		}
		get_next_arg(&line);
		inst->args++;
	}
	return (1);
}
