/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_visual.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:11:17 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/30 13:04:04 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		delete_visual(t_visual *win, t_tab *tab)
{
	int		i;

	i = 0;
	delwin(win->as);
	delwin(win->bin);
	while (i < g_lines)
	{
		free(tab[i].line);
		i++;
	}
	free(tab);
	endwin();
}
