/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:19:42 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/24 17:43:29 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		get_options(char **av, t_visual *win, t_tab **tab)
{
	int			i;
	int			j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		while (*av[i] == '-' && av[i][++j])
		{
			if (av[i][j] == 'v')
				g_option |= VISUAL_FLAG;
			else if (av[i][j] == 's')
				g_option |= SIZE_FLAG;
			else
			{
				print_error(OPTION, av[i][j], USAGE);
				exit(1);
			}
		}
	}
	if ((g_option & VISUAL_FLAG) && !setup_visual(win, tab))
	{
		ft_dprintf(2, ERROR_VISUAL"\n");
		g_option &= ~(VISUAL_FLAG);
	}
}
