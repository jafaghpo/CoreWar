/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:19:44 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/03 18:58:09 by jafaghpo         ###   ########.fr       */
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
	char		*name;
	int			i;

	if (ac < 2)
		return (print_error(NO_PARAMETER, USAGE));
	get_options(av, &win, &tab);
	i = 1;
	while (i < ac)
	{
		if (*av[i] != '-' && (name = get_name(av[i])))
		{
			if (parse_file(av[i], &win, tab))
				fill_binary(name);
			if (g_option & VISUAL_FLAG)
				reset_visual(&win, name);
			reset_bin_buffer();
			free(name);
		}
		i++;
	}
	ft_memdel((void**)&g_bin.data);
	if (g_option & VISUAL_FLAG)
		delete_visual(&win, tab);
}
