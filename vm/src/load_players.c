/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 13:50:56 by root              #+#    #+#             */
/*   Updated: 2018/02/05 18:05:01 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    load_players(t_player *players, int nb_players)
{
	int         step;
	int         i;
	t_uint32    j;

	step = MEM_SIZE / nb_players;
	i = 0;
	while (i < nb_players)
	{
		if (i * step + players[i].size < MEM_SIZE)
			ft_memcpy(g_mem + i * step, players[i].buffer, players[i].size);
		j = 0;
		while (j < players[i].size)
		{
			g_infos[j + i * step].player = i + 1;
			j++;
		}
		i++;
	}
}
