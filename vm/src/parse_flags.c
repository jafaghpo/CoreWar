/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:20:31 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/01 15:30:34 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	parse_noargs(t_args *flags, char *str)
{
	static void	(*f[256])(t_args *) = {['v'] = flags_v};
	int i;

	i = 1;
	while (str[i])
	{
		if (!f[(int)str[i]])
			ft_afferror("invalid argument2");
		f[(int)str[i]](flags);
		i++;
	}
}

static int	parse_args(t_args *flags, char **av, int *i)
{
	static int	(*f[256])() = {['d'] = get_dumps, ['n'] = get_nums, ['b'] = get_breakpoints, ['s'] = get_sleep, ['t'] = get_theme};
	int			tmp;

	if (!f[(int)av[0][1]] || av[0][2])
		ft_afferror("invalid argument");
	tmp = f[(int)av[0][1]](flags, av[1], av, i);
	return (tmp);
}

t_pfile		*parse_flags(t_args *flags, char **av, int ac)
{
	t_pfile	*files;
	int		i;
	int		tmp;

	tmp = -1;
	files = NULL;
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			if (ft_strchr(LIST_ARGS, av[i][1]))
			{
				if (i + 1 >= ac)
					ft_afferror("bad args");
				tmp = parse_args(flags, av + i, &i);
				i++;
			}
			else
				parse_noargs(flags, av[i]);
		}
		else
			files = add_file(flags, files, av[i], &tmp);
		i++;
	}
	return (files);
}
