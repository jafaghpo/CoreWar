/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:18:19 by iburel            #+#    #+#             */
/*   Updated: 2017/09/19 19:21:09 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
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
		ft_printf("compilation of %s\n", av[i]);
		if (!(name = get_name(av[i])))
			return (0);
		if ((fd = open(av[i], O_RDONLY)) == -1)
			return (puterror(ERROR_OPEN_S, 0));
		if (parse(fd))
		{
			close(fd);
			if ((fd = open(name, O_TRUNC | O_CREAT | O_WRONLY, 0644)) == -1)
				return (puterror(ERROR_OPEN_COR, 0));
			buff_put(fd);
			ft_printf("done in %s\n", name);
		}
		get_next_line(-fd, NULL);
		close(fd);
		i++;
	}
	return (0);
}
