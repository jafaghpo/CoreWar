/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_visual.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 16:33:50 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/09 13:24:15 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		delete_visual(t_visual *win, t_tab *tab)
{
	ft_memdel((void**)&tab);
	delwin(win->as);
	delwin(win->bin);
	endwin();
}
