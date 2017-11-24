/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:17:36 by niragne           #+#    #+#             */
/*   Updated: 2017/10/26 11:16:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_file		*add_file(t_args *flags, t_file *files, char *name, int *pos)
{
	t_file		*new;

	flags->nb_players += 1;
	if (flags->nb_players > MAX_PLAYERS)
		ft_afferror(ERROR_TOO_MANY_PLAYERS);
	if (!(new = malloc(sizeof(*new))))
		ft_afferror(ERROR_MALLOC);
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
