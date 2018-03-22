/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:12:19 by root              #+#    #+#             */
/*   Updated: 2018/03/22 15:48:26 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_live(t_proc *p, t_inst *args)
{
	char		str[CHAT_LINE_SIZE];
	t_int32		player;

	p->live = 1;
	g_nb_live++;
	player = get_player_id(args[0].value);
	if (player == -1)
		return ;
	g_champs[player].live = g_nb_cycle;
	if (g_flags.visu)
	{
		ft_sprintf(str, "[%6d] %.20s is alive !", g_nb_cycle,
			g_champs[player].name);
		add_line_chat(str);
	}
}
