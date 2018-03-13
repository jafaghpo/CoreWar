/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:17:36 by niragne           #+#    #+#             */
/*   Updated: 2018/03/12 17:18:48 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_pfile		*add_file(t_args *flags, t_pfile *files, char *name, int *pos)
{
	t_pfile		*new;

	flags->nb_players += 1;
	if (flags->nb_players > MAX_PLAYERS)
	{
		ft_dprintf(2, "too many player\n");
		exit(1);
	}
	if (!(new = malloc(sizeof(*new))))
	{
		ft_dprintf(2, "error malloc in add_file.c\n");
		exit(2);
	}
	new->name = name;
	new->pos = *pos;
	*pos = -1;
	if (!files)
	{
		new->next = NULL;
		return (new);
	}
	new->next = files;
	return (new);
}
