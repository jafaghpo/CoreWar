/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:12:19 by root              #+#    #+#             */
/*   Updated: 2017/12/01 19:20:11 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_live(t_proc *p, t_inst *args, t_uint32 nb_cycle)
{
    char    str[CHAT_LINE_SIZE];
    char    *tmp;
    t_int32 player;

    ft_bzero(str, sizeof(str));
    if ((player = get_player_id(args[0].value)) == -1)
        tmp = ft_strdup("ERROR");
    else
        tmp = g_champs[player].name;
    sprintf(str, "Process %3d (from player %s) says that %s is alive !", p->id, g_champs[p->player].name, tmp);
    live(args[0].value, p->player);
    p->live = nb_cycle;
    add_line_chat(str);
}