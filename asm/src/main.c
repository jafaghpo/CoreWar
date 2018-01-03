/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:19:44 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/03 22:34:47 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		print_usage(char *exec_name)
{
	ft_printf("usage: %s [-wv] file ...\n", exec_name);
	return (0);
}

static int		get_option(char **av)
{
	int			option;
	int			i;
	int			j;

	i = 0;
	option = 0;
	while (av[i])
	{
		if (av[i][0] == '-')
		{
			j = 0;
			while (av[i][j])
			{
				if (av[i][j] == 'v')
					option |= VISUAL_FLAG;
				else if (av[i][j] == 'w')
					option |= WARNING_FLAG;
				j++;
			}
		}
		i++;
	}
	return (option);
}

int				main(int ac, char **av)
{
	char		*bin_name;
	int			option;
	int			i;

	if (ac < 2)
		return (print_usage(av[0]));
	i = 1;
	option = get_option(av);
	while (i < ac)
	{
		if (av[i][0] != '-' && (bin_name = get_name(av[i])))
		{
			if (parse_file(av[i], option))
				fill_binary(bin_name);
		}
		i++;
	}
	return (0);
}
