/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:05:11 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/08 12:19:01 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		write_magic_number(void)
{
	g_bin.data[0] = (t_uint8)(COREWAR_EXEC_MAGIC >> 24);
	g_bin.data[1] = (t_uint8)(COREWAR_EXEC_MAGIC >> 16);
	g_bin.data[2] = (t_uint8)(COREWAR_EXEC_MAGIC >> 8);
	g_bin.data[3] = (t_uint8)(COREWAR_EXEC_MAGIC >> 0);
	g_bin.i = 4;
}

static int		check_syntax(t_uint8 *dest, char *line, int len)
{
	int		esc;
	int		i;

	esc = 0;
	i = 0;
	if (*line != '"')
		return (0);
	line++;
	while (*line && !(*line == '"' && !esc) && i < len)
	{
		if (*line == '\\' && !esc)
			esc = 1;
		else
		{
			dest[i++] = *line;
			esc = 0;
		}
		line++;
	}
	if (*line != '"' || i == len)
		return (0);
	line++;
	ft_delspace(&line);
	return ((!*line || *line == COMMENT_CHAR) ? i + 1 : 0);
}

static int		analize_header(char *line, t_tab *current, int *state)
{
	int		len;

	if ((len = word_equal(line, NAME_CMD_STRING)))
	{
		if (*state != 0)
			return (print_error(NO_NAME));
		if (!(len = check_syntax(g_bin.data + g_bin.i, line + len, NAME_LEN)))
			return (print_error(SYNTAX, line + len));
		current->size = NAME_LEN;
		g_bin.i = NAME_LEN + 12;
		(*state)++;
	}
	else if ((len = word_equal(line, COMMENT_CMD_STRING)))
	{
		if (*state != 1)
			return (print_error(NO_COMMENT));
		if (!(len = check_syntax(g_bin.data + g_bin.i, line + len, COM_LEN)))
			return (print_error(SYNTAX, line + len));
		current->size = COM_LEN;
		g_bin.i = HEADER_LEN;
		(*state)++;
	}
	return (1);
}

static int		parse_header(char *line, t_tab *cur, int *state, t_visual *win)
{
	if (!*line || *line == COMMENT_CHAR)
		free(cur->line);
	else if (*line == '.' && *state < 2)
	{
		if (!analize_header(line, cur, state))
			return (free_error((void*)cur->line));
		store_line(tab, cur, win);
	}
	else
	{
		free_error((void*)cur->line);
		return (print_error(HEADER_LINE, line));
	}
	return (1);
}

int				get_header(t_tab *tab, int fd, t_visual *win)
{
	t_tab	current;
	char	*line;
	int		state;

	state = 0;
	write_magic_number();
	while (get_next_line(fd, &line) > 0)
	{
		current = (t_tab){line, g_bin.data + g_bin.i, 0, 0};
		ft_delspace(&line);
		if (!parse_header(line, &current, &state, win))
			return (0);
		if (state == 2)
			return (1);
	}
	free(current.line);
	return (print_error(!state ? NO_NAME : NO_COMMENT));
}
