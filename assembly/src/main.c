/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:19:44 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/24 17:43:45 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				g_option = 0;

int				main(int ac, char **av)
{
	t_visual	win;
	t_tab		*tab;
	char		*name;
	int			i;

	if (ac < 2)
		return (print_error(NO_PARAMETER, USAGE));
	get_options(av, &win, &tab);
	i = 0;
	while (++i < ac)
	{
		if (*av[i] != '-' && (name = get_name(av[i])))
		{
			if (parse_file(av[i], &win, tab))
				fill_binary(name);
			if (g_option & VISUAL_FLAG)
				reset_visual(&win);
			ft_bzero((void*)g_bin.data, (size_t)g_bin.i);
			g_bin.i = 0;
			free(name);
		}
	}
	if (g_option & VISUAL_FLAG)
		delete_visual(&win, tab);
}
