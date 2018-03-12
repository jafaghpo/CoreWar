/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:05:03 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/12 13:46:21 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			g_state = 0;

static void	magic_number(t_tab *tab, t_visual *win)
{
	t_tab	current;

	g_bin.data[0] = (t_uint8)(COREWAR_EXEC_MAGIC >> 24);
	g_bin.data[1] = (t_uint8)(COREWAR_EXEC_MAGIC >> 16);
	g_bin.data[2] = (t_uint8)(COREWAR_EXEC_MAGIC >> 8);
	g_bin.data[3] = (t_uint8)(COREWAR_EXEC_MAGIC >> 0);
	current = (t_tab){NULL, g_bin.data, 4};
	g_bin.i = 4;
	if (g_option & VISUAL_FLAG)
		store_line(tab, &current, win);
}

static int	parse_other(char *line)
{
	char	*tmp;

	tmp = line;
	ft_delspace(&tmp);
	if (!*tmp || *tmp == COMMENT_CHAR || *tmp == '.')
	{
		free(line);
		return (1);
	}
	print_error(HEADER_LINE, tmp);
	free(line);
	return (0);
}

static int	is_header(char *line)
{
	if (word_equal(line, NAME_CMD_STRING))
	{
		g_bin.i = 4;
		return (1);
	}
	else if (word_equal(line, COMMENT_CMD_STRING))
	{
		g_bin.i = NAME_LEN + 12;
		return (2);
	}
	return (0);
}

static int	check_state(int state)
{
	if (state & ALL_DONE)
	{
		g_bin.i = HEADER_LEN;
		return (1);
	}
	else if (state & NAME_DONE)
		return (print_error(NO_COMMENT));
	else if (state & COMMENT_DONE)
		return (print_error(NO_NAME));
	return (print_error(NO_HEADER));
}

int			get_header(t_tab *tab, t_file *file, t_visual *win)
{
	char	*line;
	char	*tmp;
	int		ret;

	magic_number(tab, win);
	while (!(g_state & ALL_DONE) && (ret = ft_getline(&line, file) > 0))
	{
		if (ret == -1)
			return (print_error(strerror(errno)));
		tmp = line;
		ft_delspace(&tmp);
		if (is_header(tmp) == NAME_DONE)
		{
			if (!parse_name(line, file, tab, win))
				return (0);
		}
		else if (is_header(tmp) == COMMENT_DONE)
		{
			if (!parse_comment(line, file, tab, win))
				return (0);
		}
		else if (!parse_other(line))
			return (0);
	}
	return (check_state(g_state));
}
