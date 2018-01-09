/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:12:19 by root              #+#    #+#             */
/*   Updated: 2018/01/09 23:39:38 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_live(t_proc *p, t_inst *args)
{
    char    str[CHAT_LINE_SIZE];
    char    *tmp;
    t_int32 player;
    static char err[] = "ERROR";

    if ((player = get_player_id(args[0].value)) == -1)
        tmp = err;
    else
        tmp = g_champs[player].name;
    ft_sprintf(str, "[%6d] Process %4d (from player %.15s) says that %.15s is alive !", g_nb_cycle, p->id, g_champs[p->player].name, tmp);
    live(args[0].value);
    p->live = 1;
    g_nb_live++;
    add_line_chat(str);
}
