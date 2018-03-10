/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 13:12:53 by niragne           #+#    #+#             */
/*   Updated: 2018/03/10 16:10:32 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		print_scores(char *str)
{
	t_uint32	i;

	if (g_flags.visu)
	{
		ft_sprintf(str, "[%6d] %.20s won the game.",
			g_nb_cycle, g_champs[pick_winner()].name);
		add_line_chat(str);
		i = 1;
		while (i <= g_nb_player)
		{
			ft_sprintf(str, "%.20s: %d", g_champs[i].name, g_champs[i].live);
			add_line_chat(str);
			i++;
		}
	}
	else
	{
		ft_printf("%.20s won the game.\n", g_champs[pick_winner()].name);
		i = 1;
		while (i <= g_nb_player)
		{
			ft_printf("%.20s: %d\n", g_champs[i].name, g_champs[i].live);
			i++;
		}
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
