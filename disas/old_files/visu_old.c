/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 18:57:23 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/12/22 17:33:27 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"
#include <ncurses.h>

/*
void		setup_win(t_win *win)
{
	win->flag = ON;
	initscr();
	noecho();
	curs_set(0);
	start_color();
	keypad(stdscr, TRUE);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	win->bin_file = subwin(stdscr, LINES - 1, (COLS / 3), 1, 0);
	win->asm_file = subwin(stdscr, LINES - 1, (COLS / 3), 1, (COLS / 3));
	win->info = subwin(stdscr, LINES - 1, (COLS / 3), 1, (COLS / 3) * 2);
	attron(COLOR_PAIR(2));
	mvprintw(0, ((COLS / 3) - 11) / 2, "Binary file");
	mvprintw(0, ((COLS / 3) - 8) / 2 + (COLS / 3), "Asm file");
	mvprintw(0, ((COLS / 3) - 12) / 2 + (COLS / 3) * 2, "Informations\n");
	attroff(COLOR_PAIR(2));
	box(win->bin_file, ACS_VLINE, ACS_HLINE);
	box(win->asm_file, ACS_VLINE, ACS_HLINE);
	box(win->info, ACS_VLINE, ACS_HLINE);
	wrefresh(stdscr);
}

void		close_win(t_win *win)
{
	if (getch() == KEY_UP)
		;
	delwin(win->bin_file);
	delwin(win->asm_file);
	delwin(win->info);
	endwin();
}

void		bin_header_win(t_win *win, char *arg, int size)
{
	int		i;
	int		cursor;

	i = 0;
	cursor = ft_strlen((char*)arg);
	wprintw(win->bin_file, "\t");
	while (i < size)
	{
		if (!(i % 34))
			wprintw(win->bin_file, "\n\t");
		if (i < cursor)
		{
			wattron(win->bin_file, COLOR_PAIR(1));
			wprintw(win->bin_file, "%.2X ", arg[i]);
			wattroff(win->bin_file, COLOR_PAIR(1));
		}
		else if (arg[i])
			wprintw(win->bin_file, "%.2X ", arg[i]);
		i++;
	}
	box(win->bin_file, ACS_VLINE, ACS_HLINE);
	wrefresh(win->bin_file);
}
*/
