/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 20:56:49 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/09/11 21:40:09 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_map(t_uchar *map)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.2x ", (t_uhint)(map[i]));
		if (!((i + 1) % 64))
			ft_printf("\n");
		if (!((i + 1) % 1024))
			ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}
