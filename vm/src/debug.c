/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 19:16:53 by niragne           #+#    #+#             */
/*   Updated: 2018/01/20 18:03:06 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	debug_print_file(t_file *files)
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

void	debug_proc(t_proc *proc)
{
	ft_printf("pc : %u\n", proc->pc);
	ft_printf("op : %u\n", g_mem[proc->pc]);
	ft_printf("carry : %u\n", proc->carry);
	ft_printf("player : %u\n", proc->player);
	ft_printf("live : %u\n", proc->live);
	ft_printf("id : %u\n\n", proc->id);
}

void	debug_cycle(t_proc **cycle)
{
	int		i;
	t_proc	*tmp;

	i = 0;
	while (i < NB_CYCLE_MAX)
	{
		tmp = cycle[i];
		if (tmp)
		{
			ft_printf("pos : %d\n", i);
			while (tmp)
			{
				debug_proc(tmp);
				tmp = tmp->next;
			}
			ft_printf("\n");
		}
		i++;
	}
}

void	debug_inst(t_inst *args, int pc, int op)
{
	ft_printf("GET ARGS RENVOIE %d\n", get_args(pc, args, op));
	ft_printf("PC: %d\n", pc);
	ft_printf("%d %d %d\n", args[0].size, args[0].type, args[0].value);
	ft_printf("%d %d %d\n", args[1].size, args[1].type, args[1].value);
	ft_printf("%d %d %d\n", args[2].size, args[2].type, args[2].value);
	ft_printf("%d %d %d\n\n", args[3].size, args[3].type, args[3].value);
}
