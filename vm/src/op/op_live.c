/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:12:19 by root              #+#    #+#             */
/*   Updated: 2018/03/10 16:37:01 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_live(t_proc *p, t_inst *args)
{
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
	if (player != -1 && g_flags.visu)
	{
		ft_sprintf(str, "[%6d] %.20s is alive !", g_nb_cycle, tmp);
		add_line_chat(str);
	}
}
