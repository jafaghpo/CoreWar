/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:53:18 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/06 18:53:33 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int			wait_event(t_visual *win)
{
	int		key;

	key = getch();
	if (key == 27)
	{
		endwin();
		exit(1);
	}
	else if (win->delay)
		return (1);
	else if (key == ' ')
		return (1);
	return (0);
}
