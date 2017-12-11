/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:50:55 by niragne           #+#    #+#             */
/*   Updated: 2017/12/11 18:46:11 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_int32    get_player_id(t_uint32 octet)
{
    t_uint32 i;

    i = 0;
    while (i < g_nb_player)
    {
        if (g_champs[i].number == octet)
            return (i);
        i++;
    }
    return (-1);
}