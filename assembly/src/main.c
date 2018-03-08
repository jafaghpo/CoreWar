/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:19:44 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/08 21:49:31 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_buf			g_bin = {NULL, BUFF_SIZE, 0};
int				g_lines = 0;
char			g_error[ERROR_SIZE];

int				main(int ac, char **av)
{
	t_visual	win;
	t_tab		*tab;
	char		*path;
	int			i;

	if (!check_argv(av, &win, &tab))
		return (1);
	i = 1;
	while (i < ac)
	{
		if (*av[i] != '-')
		{
			if ((path = get_path(av[i])) && parse_file(av[i], &win, tab))
				fill_binary(path);
			if (g_option & VISUAL_FLAG)
				reset_visual(&win, path, av[i]);
			reset_buffer();
			ft_memdel((void**)&path);
		}
		i++;
	}
	ft_memdel((void**)&g_bin.data);
	if (g_option & VISUAL_FLAG)
		delete_visual(&win, tab);
}
