/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:54:00 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/13 22:55:22 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		clear_tab(t_tab *tab)
{
	int		i;

	i = 0;
	while (i < g_lines)
	{
		ft_memdel((void**)&tab[i].line);
		tab[i].line = 0;
		tab[i].pos = 0;
		tab[i].size = 0;
		i++;
	}
	g_lines = 0;
}
