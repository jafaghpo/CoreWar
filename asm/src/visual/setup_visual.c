/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:44:08 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/29 16:44:03 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	select_mode(void)
{
	int		key;

	key = 0;
	mvprintw(LINES / 2, (COLS - 33) / 2, AUTO_MANUAL);
	mvprintw(LINES / 2 + 1, (COLS - 34) / 2, STEP_MANUAL);
	while (!key)
		key = getch();
	erase();
	if (key == '\n')
		return (DELAY_USEC);
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
}

int				setup_visual(t_visual *win, t_tab **tab)
{
	initscr();
	noecho();
	curs_set(0);
	setup_color();
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, win->size.y, win->size.x);
	win->size.y -= 3;
	win->size.x /= 2 - 8;
	win->as = subwin(stdscr, LINES - 2, (COLS / 2), 2, 0);
	win->bin = subwin(stdscr, LINES - 2, (COLS / 2), 2, (COLS / 2));
	attron(COLOR_PAIR(PAIR_GREEN));
	mvprintw(LINES / 2, (COLS - 33) / 2, AUTO_MODE);
	mvprintw(LINES / 2 + 1, (COLS - 34) / 2, STEP_MODE);
	win->delay = select_mode();
	mvprintw(1, ((COLS / 2) - 8) / 2, "Asm file");
	mvprintw(1, ((COLS / 2) - 11) / 2 + (COLS / 2), "Binary file");
	attroff(COLOR_PAIR(PAIR_GREEN));
	if (!(*tab = ft_memalloc(sizeof(**tab) * win->size.y)))
		return (print_error(strerror(errno)));
	return (1);
}
