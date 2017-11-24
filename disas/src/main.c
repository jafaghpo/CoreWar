/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:18:19 by iburel            #+#    #+#             */
/*   Updated: 2017/09/20 17:49:22 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"
#include <fcntl.h>
#include <signal.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*name;
	int		i;

	if (ac < 2)
	{
		ft_printf("usage: %s file1 [file2 ...]\n", av[0]);
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		ft_printf("disassembling of %s\n", av[i]);
		if (!(name = get_name(av[i])))
			return (0);
		if ((fd = open(av[i], O_RDONLY)) == -1)
			return (puterror(ERROR_OPEN_COR, 0));
		if (disas(fd))
		{
			close(fd);
			if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
				return (puterror(ERROR_OPEN_S, 0));
			buff_put(fd);
			ft_printf("done in %s\n", name);
		}
		close(fd);
		i++;
	}
	return (0);
}
