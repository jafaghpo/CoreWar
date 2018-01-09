/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:17:36 by niragne           #+#    #+#             */
/*   Updated: 2018/01/03 15:05:08 by niragne          ###   ########.fr       */
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
