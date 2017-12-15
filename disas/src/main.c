/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:06:51 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/12/15 18:39:46 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

int			main(int ac, char **av)
{
	t_file	file;
	int		i;

	if (ac < 2)
		return (!ft_printf(USAGE, av[0]));
	i = 1;
	while (av[i])
	{
		if (!get_binary(&file, av[i]))
			;
		else if (!build_file(&file))
			;
		else
		{
			free(file.path);
			free(file.prog);
		}
		i++;
	}
	return (0);
}
