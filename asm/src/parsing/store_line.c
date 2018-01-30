/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 16:42:50 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/30 12:50:19 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	clear_tab(t_tab *tab)
{
	int		i;

	i = 0;
	while (i < g_lines)
	{
		free(tab[i].line);
		tab[i].line = 0;
		tab[i].ptr = 0;
		tab[i].size = 0;
		tab[i].new_line = 0;
		i++;
	}
	g_lines = 0;
}

int			store_line(t_tab *tab, t_tab *current, t_visual *win)
{
	if (!(g_option & VISUAL_FLAG))
	{
		free(current->line);
		return (1);
	}
	if (g_lines == win->size.y)
	{
		run_visual(tab, win);
		clear_tab(tab);
	}
	tab[g_lines].line = current->line;
	tab[g_lines].ptr = current->ptr;
	tab[g_lines].size = current->size;
	tab[g_lines].new_line = current->new_line;
	g_lines++;
	return (1);
}
