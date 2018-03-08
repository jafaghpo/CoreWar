/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:19:42 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/08 21:33:16 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			g_option = 0;

static void	check_visual(t_visual *win, t_tab **tab)
{
	if (g_option & VISUAL_FLAG)
	{
		if (!setup_visual(win, tab))
		{
			print_error(ERROR_VISUAL);
			g_option &= ~(VISUAL_FLAG);
		}
	}
}

static int	parse_option(char *av)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (av[i] == 'v')
			g_option |= VISUAL_FLAG;
		else if (av[i] == 's')
			g_option |= SIZE_FLAG;
		else
		{
			print_error(OPTION, av[i]);
			ft_dprintf(2, USAGE"\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int			check_argv(char **av, t_visual *win, t_tab **tab)
{
	int		i;
	int		file;

	i = 1;
	file = 0;
	while (av[i])
	{
		if (*av[i] == '-')
		{
			if (!parse_option(av[i]))
				return (0);
		}
		else
			file++;
		i++;
	}
	if (!file)
	{
		print_error(NO_PARAMETER);
		ft_dprintf(2, USAGE"\n");
		return (0);
	}
	check_visual(win, tab);
	return (1);
}
