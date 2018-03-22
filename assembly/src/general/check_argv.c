/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:19:42 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/22 15:09:46 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			g_option = 0;

static void	check_visual(t_visual *win, t_tab **tab, int option)
{
	if (option & VISUAL_FLAG)
	{
		if (!setup_visual(win, tab))
		{
			print_error(ERROR_VISUAL);
			option &= ~(VISUAL_FLAG);
		}
	}
	g_option = option;
}

static int	parse_option(char *av, int *option)
{
	int		i;

	i = 1;
	if (!av[1])
		return (print_error(OPTION, av[0]));
	while (av[i])
	{
		if (av[i] == 'v')
			*option |= VISUAL_FLAG;
		else if (av[i] == 's')
			*option |= SIZE_FLAG;
		else
			return (print_error(OPTION, av[i]));
		i++;
	}
	return (1);
}

int			check_argv(char **av, t_visual *win, t_tab **tab)
{
	int		i;
	int		file;
	int		option;

	i = 0;
	file = 0;
	option = 0;
	while (av[++i])
	{
		if (*av[i] == '-' && !(parse_option(av[i], &option)))
		{
			ft_dprintf(2, USAGE"\n", av[0]);
			return (0);
		}
		else if (*av[i] != '-')
			file++;
	}
	if (!file)
	{
		print_error(NO_PARAMETER);
		ft_dprintf(2, USAGE"\n", av[0]);
		return (0);
	}
	check_visual(win, tab, option);
	return (1);
}
