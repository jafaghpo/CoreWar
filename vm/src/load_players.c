/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 13:50:56 by root              #+#    #+#             */
/*   Updated: 2017/10/29 15:36:58 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    load_players(t_player *players, int nb_players)
{
    int     step;
    int     i;

    step = MEM_SIZE / nb_players;
    i = 0;
    while (i < nb_players)
    {
        ft_memcpy(g_mem + i * step, players[i].buffer, players[i].size);
        i++;
    }
}