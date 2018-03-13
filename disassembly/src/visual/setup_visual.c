/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:44:08 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/13 14:12:45 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static int		select_mode(void)
{
	int		key;

	key = 0;
	while (key != 27)
	{
		key = getch();
		if (key == '\n')
		{
			erase();
			return (1);
		}
		else if (key == ' ')
		{
			erase();
			return (0);
		}
	}
	endwin();
	exit(1);
	return (0);
}

static void		setup_color(void)
{
	start_color();
	init_pair(NC_BLACK, COLOR_BLACK, COLOR_BLACK);
	init_pair(NC_GREEN, COLOR_GREEN, COLOR_BLACK);
	init_pair(NC_YELLOW, COLOR_YELLOW, COLOR_BLACK);
	init_pair(NC_BLUE, COLOR_BLUE, COLOR_BLACK);
	init_pair(NC_RED, COLOR_RED, COLOR_BLACK);
	init_pair(NC_WHITE, COLOR_WHITE, COLOR_BLACK);
}

static void		get_win_size(t_visual *win)
{
	t_size		size;

	getmaxyx(stdscr, size.y, size.x);
	size.y -= 10;
	size.x = (size.x / 2) - 16;
	if (size.y < 0)
		size.y = 1;
	if (size.x < 0)
		size.x = 1;
	win->size = size;
}

static void		create_window(t_visual *win)
{
	attron(COLOR_PAIR(NC_GREEN));
	mvprintw(LINES / 2, (COLS - 33) / 2, AUTO_MODE);
	mvprintw(LINES / 2 + 2, (COLS - 36) / 2, STEP_MODE);
	mvprintw(LINES / 2 + 4, (COLS - 45) / 2, END_MANUAL);
	win->delay = select_mode();
	attroff(COLOR_PAIR(NC_GREEN));
	wprintw(win->bin, GO_START);
}

int				setup_visual(t_visual *win, t_tab **tab)
{
	initscr();
	noecho();
	curs_set(0);
	setup_color();
	cbreak();
	keypad(stdscr, TRUE);
	get_win_size(win);
	win->cur.x = 0;
	win->cur.y = 0;
	win->bin = subwin(stdscr, LINES - 2, (COLS / 2), 2, 0);
	win->as = subwin(stdscr, LINES - 2, (COLS / 2), 2, (COLS / 2));
	create_window(win);
	attron(COLOR_PAIR(NC_WHITE));
	if (win->delay)
		halfdelay(1);
	if (!(*tab = malloc(sizeof(**tab) * win->size.y)))
		return (print_error(strerror(errno)));
	return (1);
}
