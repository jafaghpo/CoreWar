/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_comment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:26:43 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/09 11:30:12 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

static int	parse_comment(t_visual *win, t_tab *tab, int size)
{
	t_tab	current;
	char	*line;
	char	*tmp;
	int		i;

	if (!(line = line_dup(g_asm.data + size, g_asm.i)))
		return (0);
	tmp = line;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = 0;
			current = (t_tab){line_dup_endl(line, i), g_bin.i, i};
			store_line(win, tab, current);
			line += i + 1;
			g_bin.i += i;
			i = 0;
		}
		else
			i++;
	}
	free(tmp);
	return (1);
}

int			get_comment(t_visual *win, t_tab *tab)
{
	int		size;

	size = g_asm.i;
	g_asm.i += ft_sprintf((char*)g_asm.data + g_asm.i, COMMENT_CMD_STRING);
	g_asm.i += ft_sprintf((char*)g_asm.data + g_asm.i, " \"%s\"\n\n", \
	g_bin.data + g_bin.i);
	if (g_option & VISUAL_FLAG)
	{
		if (!parse_comment(win, tab, size))
			return (0);
	}
	g_bin.i = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
	return (1);
}
