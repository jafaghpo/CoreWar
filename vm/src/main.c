/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 20:49:51 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/12/30 14:05:58 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <pthread.h>

t_uint8		g_mem[MEM_SIZE] = {0};
t_uint8		g_player[MEM_SIZE] = {0};
t_uint8		g_line_chat = CHAT_SIZE - 1;
t_uint32	g_nb_player;
char		g_chat[CHAT_SIZE][CHAT_LINE_SIZE] = {};
t_uint32	g_id;
t_champ		g_champs[4];
t_uint32	g_nb_live = 0;
t_int32   	g_cycle_to_die = CYCLE_TO_DIE;


int		main(int ac, char **av)
{
	pthread_t	tid;
	t_args		flags;
	t_file		*files;
	t_player	*players;

	if (ac < 2)
	{
		ft_printf("usage: %s [-d cycles -v] [[-n nbr] champ.cor] ...\n", av[0]);
		return (2);
	}
	
	ft_bzero(&flags, sizeof(flags));
	files = parse_flags(&flags, av, ac);

#ifdef DEBUG
	debug_flags(&flags);
	debug_print_file(files);
#endif

	fill_pos_players(files, flags.nb_players + 1);
	g_id = flags.nb_players;
	g_nb_player = flags.nb_players;

#ifdef DEBUG
	debug_print_file(files);
#endif

	players = get_players(files, flags.nb_players);

#ifdef DEBUG
	debug_players(players, flags.nb_players);
#endif

	load_players(players, flags.nb_players);

#ifdef DEBUG
	//debug_map();
#endif
	if (flags.visu)
	{
		pthread_create(&tid, NULL, vm, &flags);
		display();
	}
	else
		vm(&flags);
}
