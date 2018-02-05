/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:58:12 by niragne           #+#    #+#             */
/*   Updated: 2018/02/05 16:19:05 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	live(t_uint32 value)
{
	t_uint32 i;

	i = 1;
	while (i <= g_nb_player)
	{
		if (g_champs[i].number == value)
		{
			g_champs[i].live = g_nb_cycle;
			return ;
		}
		i++;
	}
	return ;
}
