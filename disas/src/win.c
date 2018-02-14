/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 18:49:37 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/08 12:05:13 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

void		win_put_binary(t_file *file, t_gap gap)
{
	int		i;
	int		x;
	int		len;

	getmaxyx(file->win.bin, len, x);
	x = x - 18;
	gap.end += gap.start;
	werase(file->win.bin);
	wprintw(file->win.bin, "\n\n\n\t");
	i = -1;
	len = 0;
	wattron(file->win.bin, COLOR_PAIR(6) | A_BOLD);
	while (++i < file->prog_size)
	{
		if (len > x)
			wprintw(file->win.bin, "\n\t");
		if (i == gap.start)
			wattron(file->win.bin, COLOR_PAIR(1));
		else if (i > gap.end)
			wattroff(file->win.bin, COLOR_PAIR(1));
		wprintw(file->win.bin, "%.2X ", file->prog[i]);
		len = (len > x) ? 3 : len + 3;
	}
	box(file->win.bin, ACS_VLINE, ACS_HLINE);
	wrefresh(file->win.bin);
}

void		win_key_hook(t_file *file)
{
	int		key;

	key = getch();
	if (key == 27)
	{
		endwin();
		exit(1);
	}
	else if (file->win.delay)
		return ;
	else
	{
		while (key != ' ')
			key = getch();
	}
}

static void	win_delay(t_file *file)
{
	int		key;

	key = 0;
	file->win.delay = 0;
	mvprintw(LINES / 2, (COLS - 33) / 2, AUTO_MANUAL);
	mvprintw(LINES / 2 + 1, (COLS - 34) / 2, STEP_MANUAL);
	refresh();
	while (!key)
	{
		key = getch();
		if (key == '\n')
			file->win.delay = 1;
	}
	erase();
}

void		win_setup(t_file *file)
{
	initscr();
	noecho();
	curs_set(0);
	start_color();
	keypad(stdscr, TRUE);
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_BLACK);
	file->win.bin = subwin(stdscr, LINES - 2, (COLS / 2), 2, 0);
	file->win.as = subwin(stdscr, LINES - 2, (COLS / 2), 2, (COLS / 2));
	attron(COLOR_PAIR(2));
	win_delay(file);
	mvprintw(1, ((COLS / 2) - 11) / 2, "Binary file");
	mvprintw(1, ((COLS / 2) - 8) / 2 + (COLS / 2), "Asm file");
	attroff(COLOR_PAIR(2));
	if (file->win.delay)
		halfdelay(1);
	win_put_binary(file, (t_gap){0, 3});
	box(file->win.as, ACS_VLINE, ACS_HLINE);
	refresh();
}
