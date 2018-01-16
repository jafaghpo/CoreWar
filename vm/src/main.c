/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 20:49:51 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/16 01:17:25 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <pthread.h>

t_uint8		g_mem[MEM_SIZE] = {0};
t_case		g_color[MEM_SIZE];
t_uint32	g_nb_player;
t_uint32	g_id;
t_champ		g_champs[4];
t_uint32	g_nb_live = 0;
t_int32   	g_cycle_to_die = CYCLE_TO_DIE;
float		g_sleep = 500;
t_uint32    g_nb_cycle;
t_args		g_flags;

int		main(int ac, char **av)
{
	pthread_t	tid;
	t_file		*files;
	t_player	*players;

	if (ac < 2)
	{
		ft_printf("usage: %s [-d cycles -v] [[-n nbr] champ.cor] ...\n", av[0]);
		return (2);
	}
	
	ft_bzero(&g_flags, sizeof(g_flags));
	
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		g_color[i] = (t_case){1.0, 1.0, 1.0};
		i++;
	}

	g_flags.dumps = UINT_MAX;
	files = parse_flags(&g_flags, av, ac);
	//g_flags.breakpoints[0] = 200;
	//av[ac] = NULL;
	bubble_tab(g_flags.breakpoints, g_flags.nb_breakpoints);
#ifdef DEBUG
	debug_flags(&g_flags);
	debug_print_file(files);
#endif

	fill_pos_players(files, g_flags.nb_players + 1);
	g_id = g_flags.nb_players;
	g_nb_player = g_flags.nb_players;

#ifdef DEBUG
	debug_print_file(files);
#endif

	players = get_players(files, g_flags.nb_players);

#ifdef DEBUG
	debug_players(players, g_flags.nb_players);
#endif

	load_players(players, g_flags.nb_players);
#ifdef DEBUG
	//debug_map();
#endif
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
