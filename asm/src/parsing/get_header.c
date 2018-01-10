/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:05:11 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/10 21:25:08 by jafaghpo         ###   ########.fr       */
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
			dest[i] = *line;
			i++;
			esc = 0;
		}
		line++;
	}
	if (*line != '"' || i == len)
		return (0);
	line++;
	ft_delspace(&line);
	return (!*line || *line == COMMENT_CHAR);
}

static int		analize_header(char *line, t_tab *current, int *state)
{
	int		len;

	if ((len = word_equal(line, NAME_CMD_STRING)))
	{
		if (*state != 0)
			return (print_error(0, ERROR_NAME));
		if (!(len = check_syntax(g_bin.data + g_bin.i, line + len, NAME_LEN)))
			return (print_error(0, ERROR_NAME_SYNTAX));
		current->size = len;
		g_bin.i = NAME_LEN + 12;
		(*state)++;
	}
	else if ((len = word_equal(line, COMMENT_CMD_STRING)))
	{
		if (*state != 1)
			return (print_error(0, ERROR_COM));
		if (!(len = check_syntax(g_bin.data + g_bin.i, line + len, COM_LEN)))
			return (print_error(0, ERROR_COM_SYNTAX));
		current->size = len;
		g_bin.i = NAME_LEN + COM_LEN + 16;
		(*state)++;
	}
	return (1);
}

int				get_header(t_tab *tab, int fd)
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
		if (!*line || *line == COMMENT_CHAR)
			;
		else if (*line == '.' && state < 2)
		{
			if (!analize_header(line, &current, &state))
				return (0);
			store_line(tab, &current);
			if (state == 2)
				return (1);
		}
		else
			return (print_error(0, ERROR_HEADER_LINE));
	}
	return (print_error(0, !state ? ERROR_NAME : ERROR_COM));
}
