/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_visual.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:11:17 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/19 15:58:52 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		delete_visual(t_visual *win, t_tab *tab)
{
	free(tab);
	delwin(win->as);
	delwin(win->bin);
	endwin();
}
