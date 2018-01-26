/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 13:12:53 by niragne           #+#    #+#             */
/*   Updated: 2018/01/25 21:25:17 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    end_game(void)
{
    char            str[CHAT_LINE_SIZE];
    t_uint32        i;

    usleep(100000);
    ft_memset(str, '-', sizeof(str) - 1);
    str[sizeof(str) - 1] = 0;
    add_line_chat(str);
    usleep(100000);
    ft_sprintf(str, "[%6d] %.20s won the game.", g_nb_cycle, g_champs[pick_winner()].name);
    add_line_chat(str);
    i = 1;
    while (i <= g_nb_player)
    {
        usleep(100000);
        ft_sprintf(str, "%.20s: %50d", g_champs[i].name, g_champs[i].live);
        add_line_chat(str);
        i++;
    }
}