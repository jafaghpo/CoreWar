/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 13:12:53 by niragne           #+#    #+#             */
/*   Updated: 2018/03/16 18:37:26 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		print_scores(char *str)
{
	t_uint32	i;

	if (g_flags.visu)
	{
		ft_sprintf(str, "[%6d] Player %d (%.20s) won the game.", g_nb_cycle,
			pick_winner(), g_champs[pick_winner()].name);
		add_line_chat(str);
		i = 0;
		while (++i <= g_nb_player)
		{
			ft_sprintf(str, "Player %d (%.20s): %d", i, g_champs[i].name,
				g_champs[i].live);
			add_line_chat(str);
		}
	}
	else
	{
		ft_printf("[%6d] Player %d (%.20s) won the game.\n", g_nb_cycle,
			pick_winner(), g_champs[pick_winner()].name);
		i = 0;
		while (++i <= g_nb_player)
			ft_printf("Player %d (%.20s): %d\n", i, g_champs[i].name,
				g_champs[i].live);
	}
}

void			end_game(void)
{
	char		str[CHAT_LINE_SIZE];

	if (g_flags.visu)
	{
		ft_memset(str, '-', sizeof(str) - 1);
		str[sizeof(str) - 1] = 0;
		add_line_chat(str);
	}
	print_scores(str);
}
