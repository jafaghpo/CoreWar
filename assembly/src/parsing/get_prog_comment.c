/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prog_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:18:45 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/03 20:55:47 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_syntax_error(t_uint8 *dest, char *line, int *end, int i)
{
	if (!*line)
	{
		dest[i++] = '\n';
		*end = 2;
		return (i + 1);
	}
	line++;
	ft_delspace(&line);
	if (*line != COMMENT_CHAR && *line)
		return (print_error(SYNTAX, line));
	*end = 1;
	return (i + 1);
}

static int	check_syntax(t_uint8 *dest, char *line, int *end)
{
	int		esc;
	int		i;

	esc = 0;
	i = 0;
	while (*line && !(*line == '"' && !esc))
	{
		if (i == COM_LEN)
			return (print_error(COMMENT_SIZE));
		if (*line == '\\' && !esc)
			esc = 1;
		else
		{
			dest[i++] = *line;
			esc = 0;
		}
		line++;
	}
	i = check_syntax_error(dest, line, end, i);
	return (i);
}

static int	parse_comment(char *line, t_tab *current, int *end)
{
	int		len;

	if (!*end)
	{
		if (!(len = word_equal(line, COMMENT_CMD_STRING)))
			return (print_error(HEADER_LINE, line));
		if (line[len] != '"')
			return (print_error(SYNTAX, line));
		if (!(len = check_syntax(g_bin.data + g_bin.i, line + len + 1, end)))
			return (0);
	}
	else if (!(len = check_syntax(g_bin.data + g_bin.i, line, end)))
		return (0);
	if (*end == 1)
	{
		current->size = HEADER_LEN - 4 - g_bin.i;
		g_bin.i = HEADER_LEN;
		return (1);
	}
	current->size = len - 1;
	g_bin.i += len - 1;
	return (1);
}

int			get_prog_comment(t_tab *tab, t_file *file, t_visual *win)
{
	t_tab	current;
	char	*line;
	int		ret;
	int		end;

	end = 0;
	while (end != 1 && (ret = ft_getline(&line, file)))
	{
		if (ret == -1)
			return (print_error(strerror(errno)));
		current = (t_tab){line, g_bin.data + g_bin.i, 0};
		ft_delspace(&line);
		if (!end && (!*line || *line == COMMENT_CHAR))
			free(current.line);
		else if (parse_comment(line, &current, &end))
			store_line(tab, &current, win);
		else
		{
			free(current.line);
			return (0);
		}
	}
	return (1);
}
