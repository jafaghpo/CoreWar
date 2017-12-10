/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:06:51 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/12/10 17:58:10 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

static void	delete_file(t_file *file)
{
	free(file->path);
	free(file->prog);
}

int			print_error(int errnum, const char function[], char *file, int line)
{
	ft_printf("%fd%s: %s in %s (%s:%d)\n", 2, EXEC_NAME, strerror(errnum),
	function, file, line);
	return (0);
}

int			main(int ac, char **av)
{
	t_file	file;
	int		i;

	if (ac < 2)
		return (!ft_printf(USAGE, av[0]));
	i = 1;
	while (av[i])
	{
		if (!get_binary(&file, av[i]))
			;
		//else if (!build_file(&file))
		//	;
		else
			delete_file(&file);
		i++;
	}
	return (0);
}
