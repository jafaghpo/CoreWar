/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 20:49:51 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/11/24 16:28:48 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <pthread.h>

t_uint8		g_mem[MEM_SIZE] = {0};
t_uint8		g_player[MEM_SIZE] = {0};
t_int8		g_line_chat;
t_int8		g_chat[50][30];

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

#ifdef DEBUG
	debug_print_file(files);
#endif

	players = get_players(files, flags.nb_players);

#ifdef DEBUG
	debug_players(players, flags.nb_players);
#endif

	load_players(players, flags.nb_players);

#ifdef DEBUG
	debug_map();
#endif
	pthread_create(&tid, NULL, vm, &flags);
	display();
}
