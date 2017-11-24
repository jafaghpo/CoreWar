/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 12:30:36 by iburel            #+#    #+#             */
/*   Updated: 2017/09/10 18:01:10 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	putparse(t_parse *parse)
{
	int		i;

	ft_printf("nb args : %d\n", parse->nb);
	i = 0;
	while (i < parse->nb)
	{
		ft_printf("%d\t", parse->size[i]);
		ft_printf("%s\n", parse->ptr[i]);
		i++;
	}
	ft_printf("\n");
}
