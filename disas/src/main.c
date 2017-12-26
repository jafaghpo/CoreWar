/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:06:51 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/12/26 21:22:20 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

int				print_error(char *msg)
{
	if (!msg)
		dprintf(2, "%s: %s\n", EXEC_NAME, strerror(errno));
	else
		dprintf(2, "%s: %s\n", EXEC_NAME, msg);
	return (0);
}

static int		print_usage(char *exe)
{
	dprintf(2, "usage: %s [-v] <filename>.cor\n", exe);
	return (0);
}

static void		reset_file(t_file *file, int is_flag)
{
	if (is_flag)
		return ;
	if (file->win.flag)
	{
		werase(file->win.as);
		werase(file->win.bin);
		erase();
		delwin(file->win.as);
		delwin(file->win.bin);
		refresh();
		g_line = 1;
	}
	else
		ft_printf("Creation of %s done\n", file->path);
	free(file->prog);
	free(file->path);
	ft_bzero((void*)g_buf, g_i);
	g_i = 0;
}

static void		delete_file(t_file *file)
{
	ft_strdel(&g_buf);
	if (file->win.flag)
	{
		win_key_hook(file);
		endwin();
	}
}

int				main(int ac, char **av)
{
	t_file	file;
	int		i;

	if (ac < 2)
		return (print_usage(*av));
	i = 1;
	file.win.flag = 0;
	while (av[i])
	{
		if (!ft_strcmp("-v", av[i]))
			file.win.flag = 1;
		else if (!get_binary(&file, av[i]))
			;
		else if (!parse_file(&file))
			;
		reset_file(&file, *av[i] == '-');
		i++;
	}
	delete_file(&file);
	return (0);
}
