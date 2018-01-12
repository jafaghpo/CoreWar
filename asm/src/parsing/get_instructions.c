/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 21:16:35 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/11 23:50:38 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	parse_instruction(char *line, t_label *label, t_tab *current)
{
	char	inst[20];
	int		len;
	int		op;

	if (!*line || *line == COMMENT_CHAR)
		return (1);
	if (!(len = get_opcode(line, &op)))
		return (print_error(0, INSTRUCTION));
	inst[0] = (char)op;
	inst[1] = 0;
}

static int	analize_line(char *line, t_label *label, t_tab *current)
{
	int		label_size;

	label_size = valid_label(line);
	if (label_size == -1)
		return (print_error(0, LABEL_SYNTAX));
	else if (label_size)
	{
		label->lst = add_label(label->lst, line);
		current->new_line = 1;
		line += label_size;
		ft_delspace(&line);
		return (parse_instruction(line, label, current));
	}
	else if (!parse_instruction(line), label, current)
		return (0);
	return (1);
}

int			get_instructions(t_tab *tab, t_label *label, int fd)
{
	t_tab	current;
	char	*line;
	int		ret;

	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			return (print_error(0, strerror(errno)));
		current = (t_tab){line, g_bin.data + g_bin.i, 0, 0};
		ft_delspace(&line);
		if (!*line || *line == COMMENT_CHAR)
			;
		else if (!analize_line(line, label, &current))
			return (0);
		store_line(tab, &current);
	}
	return (1);
}
