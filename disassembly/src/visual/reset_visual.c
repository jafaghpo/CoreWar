/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:46:28 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/08 19:57:51 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	reset_window(t_visual *win)
{
	wait_end();
	werase(win->as);
	werase(win->bin);
	erase();
	wrefresh(win->as);
	wrefresh(win->bin);
	refresh();
	attron(COLOR_PAIR(NC_YELLOW) | A_BOLD);
}

void		reset_visual(t_visual *win, char *name, char *arg)
{
	int		size;
	char	*path;

	if (name)
		path = name;
	else
		path = arg;
	size = ft_strlen(path);
	reset_window(win);
	if (g_error[0])
	{
		mvprintw(LINES / 2, (COLS - ft_strlen(g_error)) / 2, g_error);
		mvprintw(LINES / 2 + 2, (COLS - size - 18) / 2, ERROR_MSG, path);
	}
	else
		mvprintw(LINES / 2, (COLS - size - 20) / 2, COMPILATION_END, path);
	mvprintw(LINES / 2 + 4, (COLS - 38) / 2, NEXT_MANUAL);
	attroff(COLOR_PAIR(NC_YELLOW));
	wait_end();
	erase();
	wprintw(win->bin, GO_START);
	win->cur.x = 0;
	win->cur.y = 0;
}
