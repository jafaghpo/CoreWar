/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 20:49:51 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/12/03 18:42:13 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <pthread.h>

t_uint8		g_mem[MEM_SIZE] = {0};
t_uint32	g_id;

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
	g_id = flags.nb_players - 1;

#ifdef DEBUG
	debug_print_file(files);
#endif

	players = get_players(files, flags.nb_players);

#ifdef DEBUG
	debug_players(players, flags.nb_players);
#endif

	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		g_case[i] = (t_case){1.f, 1.f, 1.f};
		i++;
	}
	load_players(players, flags.nb_players);

#ifdef DEBUG
	//debug_map();
#endif
	pthread_create(&tid, NULL, vm, &flags);
	display();
}
