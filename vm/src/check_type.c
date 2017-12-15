/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:40:44 by ggregoir          #+#    #+#             */
/*   Updated: 2017/12/15 18:38:43 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_type(int op, t_inst *type)
{
	static int	tab[4] = {0, 1, 2, 4};
	int			i;

	i = 0;
	while (i < g_optab[op].nb_args)
	{
		if (!(tab[type[i].type] & g_optab[op].args[i]))
			return (0);
		if (type[i].type == 0)
			return (0);
		i++;
	}
	while (i < 4)
	{
		if (type[i].type)
			return (0);
		i++;
	}
	return (1);
}
