/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 21:16:35 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/08 11:55:40 by jafaghpo         ###   ########.fr       */
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
		line += label_size + 1;
		ft_delspace(&line);
		return (parse_instruction(line, label, current));
	}
	else if (!parse_instruction(line, label, current))
		return (0);
	return (1);
}

int			get_instructions(t_tab *tab, t_label *label, int fd, t_visual *win)
{
	t_tab	current;
	char	*line;
	int		ret;

	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			return (print_error(strerror(errno)));
		current = (t_tab){line, g_bin.data + g_bin.i, 0};
		ft_delspace(&line);
		if (!*line || *line == COMMENT_CHAR)
		{
			free(current.line);
			continue ;
		}
		else if (!analize_line(line, label, &current))
			return (free_error((void*)current.line));
		store_line(tab, &current, win);
	}
	ft_memdel((void**)&line);
	if (g_lines && (g_option & VISUAL_FLAG))
		run_visual(tab, win);
	return (1);
}
