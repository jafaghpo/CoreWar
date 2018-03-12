/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:18:45 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/11 15:17:18 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	parse_com_long(int size, t_file *file, t_tab *tab, t_visual *win)
{
	t_tab	current;
	char	*line;
	int		ret;
	int		len;

	while ((g_state & NEXT_LINE) && (ret = ft_getline(&line, file) > 0))
	{
		if (ret == -1)
			return (print_error(strerror(errno)));
		current = (t_tab){line, g_bin.data + g_bin.i, 0};
		if (!(len = check_syntax(g_bin.data + g_bin.i, line))
		|| size + len > COM_LEN)
		{
			free(current.line);
			return (print_error(SYNTAX, line));
		}
		size += len - 1;
		current.size = len - 1;
		if (!(g_state & NEXT_LINE))
			current.size = HEADER_LEN - 4 - g_bin.i;
		g_bin.i = (g_state & NEXT_LINE) ? g_bin.i + len - 1 : HEADER_LEN;
		store_line(tab, &current, win);
		g_state |= (g_state & NAME_DONE) ? ALL_DONE : COMMENT_DONE;
	}
	return (1);
}

int			parse_comment(char *line, t_file *file, t_tab *tab, t_visual *win)
{
	int		len;
	t_tab	current;

	current = (t_tab){line, g_bin.data + g_bin.i, 0};
	ft_delspace(&line);
	len = word_equal(line, COMMENT_CMD_STRING);
	if (line[len] != '"'
	|| !(len = check_syntax(g_bin.data + g_bin.i, line + len + 1))
	|| len > COM_LEN)
	{
		free(current.line);
		return (print_error(SYNTAX, line));
	}
	if (!(g_state & NEXT_LINE))
	{
		current.size = HEADER_LEN - 4 - g_bin.i;
		store_line(tab, &current, win);
		g_state |= (g_state & NAME_DONE) ? ALL_DONE : COMMENT_DONE;
		return (1);
	}
	current.size = len - 1;
	g_bin.i += len - 1;
	store_line(tab, &current, win);
	return (parse_com_long(len - 1, file, tab, win));
}
