/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:12:19 by root              #+#    #+#             */
/*   Updated: 2018/01/04 18:40:21 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_live(t_proc *p, t_inst *args, t_uint32 g_nb_cycle)
{
    char    str[CHAT_LINE_SIZE];
    char    *tmp;
    t_int32 player;
    static char err[] = "ERROR";

    if ((player = get_player_id(args[0].value)) == -1)
        tmp = err;
    else
        tmp = g_champs[player].name;
    sprintf(str, "[%6d] Process %4d (from player %.15s) says that %.15s is alive !", g_nb_cycle, p->id, g_champs[p->player].name, tmp);
    live(args[0].value, p->player);
    p->live = 1;
    g_nb_live++;
    (void)str;
    (void)g_nb_cycle;
    add_line_chat(str);
}
