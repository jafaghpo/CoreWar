/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 21:16:35 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/03 18:10:44 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	parse_instruction(char *line, t_label *label, t_tab *current)
{
	t_inst	inst;
	int		len;
	int		op;

	if (!*line || *line == COMMENT_CHAR)
		return (1);
	if (!(len = get_opcode(line, &op)))
		return (print_error(UNKNOWN_INST, line));
	inst.size = 1 + g_op[op].octal;
	ft_bzero((void*)inst.data, 20);
	inst.data[0] = (char)op;
	inst.args = 0;
	line += len;
	ft_delspace(&line);
	if (!parse_arguments(line, label, &inst))
		return (0);
	if (inst.args != g_op[op].nb_args)
		return (print_error(ARG_NUMBER, line));
	current->size = inst.size;
	if (!add_instruction(&inst))
		return (0);
	return (1);
}

static int	analize_line(char *line, t_label *label, t_tab *current)
{
	int		label_size;

	label_size = valid_label(line);
	if (label_size == -1)
		return (print_error(LABEL_SYNTAX, line));
	else if (label_size)
	{
		label->lst = add_label(label->lst, line, label_size);
		if (!label->lst)
			return (0);
		line += label_size + 1;
		ft_delspace(&line);
		return (parse_instruction(line, label, current));
	}
	else if (!parse_instruction(line, label, current))
		return (0);
	return (1);
}

int			get_inst(t_tab *tab, t_label *label, t_file *file, t_visual *win)
{
	t_tab	current;
	char	*line;
	int		ret;

	while ((ret = ft_getline(&line, file)))
	{
		if (ret == -1)
			return (print_error(strerror(errno)));
		current = (t_tab){line, g_bin.data + g_bin.i, 0};
		ft_delspace(&line);
		if (!*line || *line == COMMENT_CHAR || *line == '.')
		{
			free(current.line);
			continue ;
		}
		else if (!analize_line(line, label, &current))
		{
			free(current.line);
			return (0);
		}
		store_line(tab, &current, win);
	}
	if (g_lines && (g_option & VISUAL_FLAG))
		run_visual(tab, win);
	return (1);
}
