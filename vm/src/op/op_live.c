/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:12:19 by root              #+#    #+#             */
/*   Updated: 2018/01/30 09:30:11 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_live(t_proc *p, t_inst *args)
{
    static char err[] = "UNDEFINED";
    char        str[CHAT_LINE_SIZE];
    char        *tmp;
    t_int32     player;

    p->live = 1;
    g_nb_live++;
    if ((player = get_player_id(args[0].value)) == -1)
        tmp = err;
    else
    {
        g_champs[player].live = g_nb_cycle;
        tmp = g_champs[player].name;
    }
    if (player != -1)
    {
        ft_sprintf(str, "[%6d] player %.15s says that %.15s is alive !", g_nb_cycle, g_champs[p->player].name, tmp);
        add_line_chat(str);
    }
}
