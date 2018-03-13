/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:25:36 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/13 22:28:27 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

static int	parse_name(t_visual *win, t_tab *tab)
{
	t_tab	current;
	char	*line;
	char	*tmp;
	int		i;

	if (!(line = line_dup((char*)g_asm.data, g_asm.i)))
		return (0);
	tmp = line;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			current = (t_tab){line_dup(line, i + 1), g_bin.i, i};
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

int			get_name(t_visual *win, t_tab *tab)
{
	t_tab	current;

	g_asm.i += ft_sprintf((char*)g_asm.data, NAME_CMD_STRING);
	g_asm.i += ft_sprintf((char*)g_asm.data + g_asm.i, " \"%s\"\n", \
	g_bin.data + MAGIC_LEN);
	if (g_option & VISUAL_FLAG)
	{
		current = (t_tab){NULL, 0, MAGIC_LEN};
		store_line(win, tab, current);
		if (!ft_memchr(g_bin.data + 4, '\n', PROG_NAME_LENGTH))
		{
			current = (t_tab){line_dup((char*)g_asm.data, g_asm.i),
				g_bin.i, PROG_NAME_LENGTH};
			store_line(win, tab, current);
		}
		else if (!parse_name(win, tab))
			return (0);
		current = (t_tab){NULL, PROG_NAME_LENGTH + 8, 4};
		store_line(win, tab, current);
	}
	g_bin.i = PROG_NAME_LENGTH + 12;
	return (1);
}
