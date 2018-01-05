/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:58:12 by niragne           #+#    #+#             */
/*   Updated: 2018/01/05 18:48:10 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    live(t_uint32 value)
{
    t_uint32 i;

    i = 0;
    while (i < g_nb_player)
    {
        if (g_champs[i].number == value)
        {
            g_champs[i].live = g_nb_cycle;
            return ;
        }
        i++;
    }
    return ;
}