/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_visual.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 22:09:40 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/13 19:00:52 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void		set_bin_attribute(t_visual *win, char *status)
{
	static int	color = 1;

	if (color > 4)
		color = 1;
	if (!ft_strcmp(status, "ON"))
		wattron(win->bin, COLOR_PAIR(color) | A_BOLD);
	else
	{
		wattroff(win->bin, COLOR_PAIR(color));
		color++;
	}
}

static void		set_asm_attribute(t_visual *win, char *status)
{
	static int	color = 1;

	if (color > 4)
		color = 1;
	if (!ft_strcmp(status, "ON"))
		wattron(win->as, COLOR_PAIR(color) | A_BOLD);
	else
	{
		wattroff(win->as, COLOR_PAIR(color));
		color++;
	}
}

static void		display_bin(t_tab *tab, t_visual *win, int line)
{
	int				i;

	i = -1;
	set_bin_attribute(win, "ON");
	while (++i < tab[line].size)
	{
		if (win->cur.x >= win->size.x)
		{
			wprintw(win->bin, GO_NEXT);
			win->cur.x = 0;
			win->cur.y++;
		}
		if (win->cur.y >= win->size.y)
		{
			werase(win->bin);
			wprintw(win->bin, GO_START);
			win->cur.y = 0;
			win->cur.x = 0;
		}
		wprintw(win->bin, "%.2X ", g_bin.data[tab[line].pos + i]);
		win->cur.x += 3;
	}
	set_bin_attribute(win, "OFF");
}

static void		display_asm(t_tab *tab, t_visual *win, int line)
{
	int		i;

	i = 0;
	werase(win->as);
	wprintw(win->as, GO_START);
	while (i < line)
	{
		if (tab[i].line)
			wprintw(win->as, "%s\t", tab[i].line);
		i++;
	}
	set_asm_attribute(win, "ON");
	if (tab[i].line)
		wprintw(win->as, "%s\t", tab[i].line);
	set_asm_attribute(win, "OFF");
}

void			run_visual(t_tab *tab, t_visual *win)
{
	int		line;
	int		run;

	line = 0;
	run = 1;
	while (line < g_lines)
	{
		if (run)
		{
			mvprintw(1, ((COLS / 2) - 11) / 2, "Binary file");
			mvprintw(1, ((COLS / 2) - 8) / 2 + (COLS / 2), "Asm file");
			display_asm(tab, win, line);
			display_bin(tab, win, line);
			box(win->as, ACS_VLINE, ACS_HLINE);
			box(win->bin, ACS_VLINE, ACS_HLINE);
			wrefresh(win->as);
			wrefresh(win->bin);
			line++;
		}
		run = wait_event(win);
	}
	clear_tab(tab);
}
