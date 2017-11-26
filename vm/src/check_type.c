/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:40:44 by ggregoir          #+#    #+#             */
/*   Updated: 2017/11/25 18:07:41 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_type(int op, t_inst *type)
{
	static int	tab[4] = {0, 1, 2, 4};
	int			i;

	i = 0;
	while (i < op_tab[op].nb_args)
	{
		if (!(tab[type[i].type] & op_tab[op].args[i]))
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
