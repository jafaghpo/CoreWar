/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:19:44 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/02 17:27:42 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				g_option = 0;

static int		get_option(char **av)
{
	int			i;
	int			j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (*av[i] == '-' && av[i][j])
		{
			if (av[i][j] == 'v')
				g_option |= VISUAL_FLAG;
			else if (av[i][j] == 's')
				g_option |= SIZE_FLAG;
			else
				return (print_error(OPTION, av[i][j], USAGE));
			j++;
		}
		i++;
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_visual	win;
	t_tab		*tab;
	char		*bin_name;
	int			i;

	if (ac < 2)
		return (print_error(NO_PARAMETER, USAGE));
	i = 1;
	if (!get_option(av))
		return (0);
	if ((g_option & VISUAL_FLAG) && !setup_visual(&win, &tab))
		visual_error(&g_option);
	while (i < ac)
	{
		if (*av[i] != '-' && (bin_name = get_name(av[i])))
		{
			if (parse_file(av[i], &win, tab))
				fill_binary(bin_name);
			if (g_option & VISUAL_FLAG)
				delete_visual(&win, tab, (i + 1 == ac));
		}
		i++;
	}
	return (0);
}
