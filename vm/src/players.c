/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:31:41 by niragne           #+#    #+#             */
/*   Updated: 2018/02/01 15:30:33 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		load_players(t_args *flags, t_player **players, t_uchar *map)
{
	int i;

	i = 0;
	while (i < flags->nb_players)
	{
		(*players)[i].pc = i * (MEM_SIZE / flags->nb_players);
		ft_memcpy(map + i * (MEM_SIZE / flags->nb_players),
		(*players)[i].buffer, (*players)[i].size);
		i++;
	}
}

void		fill_players(t_args *flags, t_pfile **files, t_player **p, int *used)
{
	int i;

	i = 0;
	while (*files)
	{
		if ((*files)->pos == -1)
		{
			while (used[flags->nb_players - 1 - i])
			{
				if (i > flags->nb_players)
					ft_afferror(ERROR_TOO_MANY_PLAYERS);
				i++;
			}
			(*p)[flags->nb_players - 1 - i] = get_mem((*files)->name);
			i++;
		}
		(*files) = (*files)->next;
	}
}

void		verif_players(t_args *flags, t_player *players)
{
	int		i;

	i = 0;
	while (i < flags->nb_players)
	{
		if (!players[i].size)
			ft_afferror(ERROR_CHAMP_POS);
		i++;
	}
}

void		get_players(t_args *flags, t_pfile **files, t_player **players)
{
	int		i;
	t_pfile	*backup;
	int		used[flags->nb_players];

	i = 0;
	backup = *files;
	ft_bzero(used, sizeof(used));
	if (!(*players = ft_memalloc(sizeof(t_player) * flags->nb_players)))
		ft_afferror(ERROR_MALLOC);
	while (*files)
	{
		if ((*files)->pos != -1)
		{
			if (used[(*files)->pos - 1] == 1)
				ft_afferror(ERROR_DUPLICATE_POS);
			(*players)[(*files)->pos - 1] = get_mem((*files)->name);
			used[(*files)->pos - 1] = 1;
		}
		(*files) = (*files)->next;
		i++;
	}
	*files = backup;
	fill_players(flags, files, players, used);
	verif_players(flags, *players);
}
