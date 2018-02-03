/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:38:57 by iburel            #+#    #+#             */
/*   Updated: 2018/02/03 14:42:13 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    free_players(t_player *players)
{
    t_uint8     i;

    i = 0;
    while (i < g_nb_player)
    {
//        free(players[i].name);
//        free(players[i].comment);
//        free(players[i].buffer);
        (void)players;
        i++;
    }
}