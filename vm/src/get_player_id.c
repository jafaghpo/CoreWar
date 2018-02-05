/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:50:55 by niragne           #+#    #+#             */
/*   Updated: 2018/02/05 13:42:08 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_int32		get_player_id(t_uint32 octet)
{
	t_uint32 i;

	i = 1;
	while (i <= g_nb_player)
	{
		if (g_champs[i].number == octet)
			return (i);
		i++;
	}
	return (-1);
}
