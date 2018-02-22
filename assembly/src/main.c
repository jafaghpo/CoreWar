/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:19:44 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/22 18:38:11 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				g_option = 0;

static void		get_option(char **av, t_visual *win, t_tab **tab)
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

int				main(int ac, char **av)
{
	t_visual	win;
	t_tab		*tab;
	char		*bin_name;
	int			i;

	if (ac < 2)
		return (print_error(NO_PARAMETER, USAGE));
	i = 0;
	get_option(av, &win, &tab);
	while (++i < ac)
	{
		if (*av[i] != '-' && (bin_name = get_name(av[i])))
		{
			if (parse_file(av[i], &win, tab))
				fill_binary(bin_name);
			if (g_option & VISUAL_FLAG)
				reset_visual(&win);
			ft_bzero((void*)g_bin.data, (size_t)g_bin.i);
			g_bin.i = 0;
			free(bin_name);
		}
	}
	if (g_option & VISUAL_FLAG)
		delete_visual(&win, tab);
	while (1);
}
