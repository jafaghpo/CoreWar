/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 20:49:51 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/03 15:02:26 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <pthread.h>

void	attend(void)
{
	while (1);
}

int		main(int ac, char **av)
{
	pthread_t	tid;
	t_pfile		*files;
	t_player	*players;

//	atexit(attend);
	if (ac < 2)
	{
		ft_printf("usage: %s [-d cycles -v] [[-n nbr] champ.cor] ...\n", av[0]);
		return (2);
	}
	g_flags.dumps = UINT_MAX;
	files = parse_flags(&g_flags, av, ac);
	if (g_flags.nb_players == 0)
	{
		ft_printf("error: no players\n");
		return (3);
	}
	if (!(g_champs = malloc(sizeof(*g_champs) * (g_flags.nb_players + 1))))
		return (4);
	g_champs[0].color = g_theme.color_empty;
	bubble_tab(g_flags.breakpoints, g_flags.nb_breakpoints);
	fill_pos_players(files, g_flags.nb_players + 1);
	g_nb_process = g_flags.nb_players;
	init_gid(g_nb_process);
	g_nb_player = g_flags.nb_players;
	players = get_players(files, g_flags.nb_players);
	load_players(players, g_flags.nb_players);
	free_files(files);
	if (g_flags.visu)
	{
		pthread_create(&tid, NULL, keyhook, NULL);		
		pthread_create(&tid, NULL, vm, &g_flags);
		display();
	}
	else
	{
		g_sleep = 0;
		g_pause = 0;
		vm(&g_flags);
	}
}
