/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 15:02:18 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/13 22:56:41 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

t_buf			g_bin = {NULL, 0, 0};
t_buf			g_asm = {NULL, BUFF_SIZE, 0};
int				g_lines = 0;
char			g_error[ERROR_LEN];

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
			if ((path = get_path(av[i])) && get_binary(av[i]))
				parse_binary(path, &win, tab);
			if (g_option & VISUAL_FLAG)
				reset_visual(&win, tab, path, av[i]);
			reset_buffer();
			ft_memdel((void**)&path);
		}
		i++;
	}
	ft_memdel((void**)&g_asm.data);
	if (g_option & VISUAL_FLAG)
		delete_visual(&win, tab);
}
