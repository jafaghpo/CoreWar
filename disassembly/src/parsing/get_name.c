/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:25:36 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/07 15:22:15 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

int			get_name(t_visual *win, t_tab *tab)
{
	t_tab	current;
	int		tmp;
	char	*line;

	g_asm.i += ft_sprintf((char*)g_asm.data, NAME_CMD_STRING);
	tmp = g_asm.i + 4;
	g_asm.i += ft_sprintf((char*)g_asm.data + g_asm.i, " \"%s\"\n",
													g_bin.data + MAGIC_LEN);
	if (g_option & VISUAL_FLAG)
	{
		if (!(line = line_dup(g_asm.data, g_asm.i)))
			return (0);
		current = (t_tab){line, g_bin.i, g_asm.i - tmp};
		store_line(win, tab, current);
	}
	g_bin.i = PROG_NAME_LENGTH + 12;
	return (1);
}
