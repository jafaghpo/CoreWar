/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:54:54 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/10 21:31:10 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_buf			g_bin = {NULL, BUFF_SIZE, 0};
int				g_lines = 0;

static void		release_memory(t_tab *tab)
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

static void		debug_bin(void)
{
	int		i;

	i = 0;
	while (i < 320)
	{
		if (!(i % 32))
			printf("\n");
		printf("%.2X ", g_bin.data[i]);
		i++;
	}
	printf("\n");
}

int				parse_file(char *name)
{
	t_tab		*tab;
	t_label		label;
	int			fd;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (print_error(0, ERROR_OPEN, name, strerror(errno)));
	if (!(tab = ft_memalloc(sizeof(*tab) * TAB_SIZE)))
		return (print_error(0, strerror(errno)));
	if (!(g_bin.data = ft_memalloc(sizeof(*g_bin.data) * BUFF_SIZE)))
		return (print_error(0, strerror(errno)));
	if (!get_header(tab, fd))
		return (0);
	if (!get_instructions(tab, &label, fd))
		return (0);
	if (!check_labels(&label))
		return (0);
	if (g_option & VISUAL_FLAG)
		run_visual(tab);
	//debug_bin();
	release_memory(tab);
	close(fd);
	return (1);
}
