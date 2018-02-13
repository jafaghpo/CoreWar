/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 19:16:53 by niragne           #+#    #+#             */
/*   Updated: 2018/02/13 16:27:48 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	debug_print_pfile(t_pfile *files)
{
	ft_printf("\n");
	while (files)
	{
		ft_printf("(%d) %s\n", files->pos, files->name);
		files = files->next;
	}
	ft_printf("\n");
}

void	debug_flags(t_args *flags)
{
	ft_printf("\ndump visu\n");
	ft_printf("%4d %4d\n", flags->dump, flags->visu);
	ft_printf("dumps : %d\n", flags->dumps);
	ft_printf("nb players : %d\n\n", flags->nb_players);
}

void	debug_players(t_player *players, int nb_players)
{
	int		i;

	i = 0;
	while (i < nb_players)
	{
		ft_printf("joueur %d :\n", i);
		ft_printf("name : %s\n", players[i].name);
		ft_printf("comment : %s\n", players[i].comment);
		ft_printf("size : %u\n\n", players[i].size);
		i++;
	}
}

void	debug_map(void)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%3.2x", g_mem[i]);
		if ((i + 1) % 64 == 0)
			ft_printf("\n");
		i++;
	}
}
