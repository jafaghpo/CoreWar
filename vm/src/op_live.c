/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:12:19 by root              #+#    #+#             */
/*   Updated: 2017/12/16 12:10:33 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_live(t_proc *p, t_inst *args, t_uint32 nb_cycle)
{
    char    str[CHAT_LINE_SIZE];
    char    *tmp;
    t_int32 player;
    static char err[] = "ERROR";

    (void)nb_cycle;
    ft_bzero(str, sizeof(str));
    if ((player = get_player_id(args[0].value)) == -1)
        tmp = err;
    else
        tmp = g_champs[player].name;
    sprintf(str, "Process %4d (from player %.15s) says that %.15s is alive !", p->id, g_champs[p->player].name, tmp);
    live(args[0].value, p->player);
    p->live = 1;
    g_nb_live++;
//    add_line_chat(str);
}
