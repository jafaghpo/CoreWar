/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_comment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:26:43 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/08 12:36:49 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

int			get_comment(t_visual *win, t_tab *tab)
{
	t_tab	current;
	int		tmp;
	char	*line;
	int		i;

	i = g_asm.i;
	g_asm.i += ft_sprintf((char*)g_asm.data + g_asm.i, COMMENT_CMD_STRING);
	tmp = g_asm.i + 4;
	g_asm.i += ft_sprintf((char*)g_asm.data + g_asm.i, " \"%s\"\n\n",
													g_bin.data + g_bin.i);
	if (g_option & VISUAL_FLAG)
	{
		if (!(line = line_dup(g_asm.data + i, g_asm.i)))
			return (0);
		current = (t_tab){line, g_bin.i, g_asm.i - tmp};
		store_line(win, tab, current);
	}
	g_bin.i = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
	return (1);
}
