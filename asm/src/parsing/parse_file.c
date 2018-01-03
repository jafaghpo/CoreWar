/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:54:54 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/03 23:06:39 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_buf		g_bin = {NULL, BSIZE, 0};

static	void	release_memory(t_tab *tab)
{
	int		i;

	i = 0;
	while (tab[i].line)
	{
		ft_memdel((void**)&tab[i].line);
		i++;
	}
	ft_memdel((void**)&tab);
	ft_memdel((void**)&g_bin.data);
}

int				parse_file(char *name, int option)
{
	t_tab	*tab;
	int		fd;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (print_error(NULL));
	if ((tab = ft_memalloc(sizeof(*tab) * BSIZE)))
		return (print_error(NULL));
	if ((g_bin.data = ft_memalloc(sizeof(*g_bin.data) * BSIZE)))
		return (print_error(NULL));
	if (!parse_header(tab, option))
		return (0);
	if (!parse_core(tab))
		return (0);
	if (option & VISUAL_FLAG)
		run_visual(tab);
	release_memory(tab);
	close(fd);
	return (1);
}
