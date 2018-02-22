/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:46:28 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/19 15:47:41 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	reset_visual(t_visual *win)
{
	wait_end();
	werase(win->as);
	werase(win->bin);
	wprintw(win->bin, "\n\n\n\t");
	win->cur.x = 0;
	win->cur.y = 0;
}
