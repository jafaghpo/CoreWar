/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:43:52 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/08 17:27:31 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		store_line(t_visual *win, t_tab *tab, t_tab current)
{
	if (g_lines == win->size.y)
		run_visual(tab, win);
	tab[g_lines].line = current.line;
	tab[g_lines].pos = current.pos;
	tab[g_lines].size = current.size;
	g_lines++;
}
