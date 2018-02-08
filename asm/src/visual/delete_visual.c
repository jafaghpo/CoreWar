/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_visual.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:11:17 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/04 17:39:00 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	wait_end(void)
{
	int		key;

	key = 0;
	while (key != 27)
	{
		key = getch();
		if (key == ' ')
			return ;
	}
	endwin();
	exit(1);
}

void		delete_visual(t_visual *win, t_tab *tab, int end)
{
	int		i;

	i = 0;
	wait_end();
	if (!end)
	{
		werase(win->as);
		werase(win->bin);
		wprintw(win->bin, "\n\n\n\t");
		win->cur.x = 0;
		win->cur.y = 0;
		return ;
	}
	while (tab[i].line)
	{
		free(tab[i].line);
		i++;
	}
	free(tab);
	delwin(win->as);
	delwin(win->bin);
	endwin();
}
