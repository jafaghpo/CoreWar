/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:12:19 by root              #+#    #+#             */
/*   Updated: 2018/02/12 14:22:08 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_live(t_proc *p, t_inst *args)
{
	static char	err[] = "UNDEFINED";
	char		str[CHAT_LINE_SIZE];
	char		*tmp;
	t_int32		player;

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
		ft_sprintf(str, "[%6d] %.10s is alive !", g_nb_cycle, tmp);
		add_line_chat(str);
	}
}
