/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:40:44 by ggregoir          #+#    #+#             */
/*   Updated: 2018/02/13 18:50:31 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_type(int op, t_inst *type)
{
	static int	tab[4] = {0, 1, 2, 4};
	int			i;

	i = 0;
	while (i < g_op_tab[op].nb_args)
	{
		if (!(tab[type[i].type] & g_op_tab[op].args[i]))
			return (0);
		if (type[i].type == 0)
			return (0);
		i++;
	}
	return (1);
}
