/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_winner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:42:15 by niragne           #+#    #+#             */
/*   Updated: 2017/12/27 17:45:48 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int    pick_winner(void)
{
    int max;
    t_uint32 i;
    t_uint32 j;

    max = -1;
    i = 0;
    while (i < g_nb_player)
    {
        if ((int)g_champs[i].live > max)
        {
            max = g_champs[i].live;
            j = i;
        }
        i++;
    }
    ft_printf("PICK WINNER %d\n",j );
    return (j);
}