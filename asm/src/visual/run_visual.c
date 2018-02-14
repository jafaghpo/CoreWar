/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_visual.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 22:09:40 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/14 22:12:47 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		wait_event(int delay)
{
	if (delay)
		usleep(delay);
	else
	{
		while (getch() != ' ')
			;
	}
}

static void		select_color(t_visual *win)
{
	static int	color = 1;

	if (color > 4)
		color = 1;
	wattron(win->bin, COLOR_PAIR(color));
	color++;
}

static void		display_bin(t_tab *tab, t_visual *win, int line)
{
	static t_size	current = {0, 0};
	int				i;

	i = 0;
	select_color(win);
	while (i < tab[line].size)
	{
		if (current.x >= win->size.x)
		{
			wprintw(win->bin, "\n\t");
			current.x = 0;
			current.y++;
		}
		if (current.y >= win->size.y)
		{
			werase(win->bin);
			wprintw(win->bin, "\n\n\n\t");
			current.y = 0;
			current.x = 0;
		}
		i++;
		wprintw(win->bin, "%.2X ", tab[line].ptr[i]);
		current.x += 3;
	}
	box(win->bin, ACS_VLINE, ACS_HLINE);
}

static void		display_asm(t_tab *tab, t_visual *win, int line)
{
	int		i;

	i = 0;
	werase(win->as);
	wprintw(win->as, "\n\n\n\t");
	wattron(win->as, COLOR_PAIR(NC_BLACK) | A_BOLD);
	while (i < g_lines)
	{
		if (i == line)
		{
			wattron(win->as, COLOR_PAIR(NC_YELLOW));
			wprintw(win->as, tab[i].line);
			wattroff(win->as, COLOR_PAIR(NC_YELLOW));
		}
		else
			wprintw(win->as, tab[i].line);
		wprintw(win->as, "\n\t");
		i++;
	}
	box(win->as, ACS_VLINE, ACS_HLINE);
}

void			run_visual(t_tab *tab, t_visual *win)
{
	int		line;

	line = 0;
	while (line < g_lines)
	{
		wait_event(win->delay);
		display_asm(tab, win, line);
		display_bin(tab, win line);
		wrefresh(win->as);
		wrefresh(win->bin);
		line++;
	}
}
