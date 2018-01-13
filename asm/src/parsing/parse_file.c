/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:54:54 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/13 01:57:07 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_buf			g_bin = {NULL, BUFF_SIZE, 0};
int				g_lines = 0;

static void		release_memory(t_tab *tab)
{
	int		i;

	i = 0;
	if (!(g_option & VISUAL_FLAG))
		return ;
	while (tab[i].line)
	{
		ft_memdel((void**)&tab[i].line);
		i++;
	}
	ft_memdel((void**)&tab);
	ft_memdel((void**)&g_bin.data);
}

/*
**	DEBUG FUNCTIONS
*/

static void		debug_bin(void)
{
	int		i;

	i = 0;
	while (i < 3000)
	{
		if (!(i % 32))
			printf("\n");
		printf("%.2X ", g_bin.data[i]);
		i++;
	}
	printf("\n\n");
}

static void		debug_label(t_label *label)
{
	t_lstlb		*tmp;

	tmp = label->lst;
	printf("list of declared labels:\n");
	while (tmp)
	{
		printf("name: %s addr: %d\n", tmp->name, tmp->addr);
		tmp = tmp->next;
	}
}

static void		debug_tab(t_tab *tab)
{
	int		i;

	if (!(g_option & VISUAL_FLAG))
		return ;
	i = 0;
	while (tab[i].line)
	{
		printf("line: %s\n", tab[i].line);
		printf("ptr: %s\n", tab[i].ptr);
		printf("size: %d\n", tab[i].size);
		printf("new_line: %d\n", tab[i].new_line);
		printf("\n");
		i++;
	}
}

/*
**	END OF DEBUG
*/

int				parse_file(char *name)
{
	t_tab		*tab;
	t_label		label;
	int			fd;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (print_error(UNKNOWN_FILE, name, strerror(errno)));
	if (g_option & VISUAL_FLAG)
	{
		if (!(tab = ft_memalloc(sizeof(*tab) * TAB_SIZE)))
			return (print_error(strerror(errno)));
	}
	label = (t_label){0, 0};
	if (!(g_bin.data = ft_memalloc(sizeof(*g_bin.data) * BUFF_SIZE)))
		return (print_error(strerror(errno)));
	if (!get_header(tab, fd) || !get_instructions(tab, &label, fd))
		return (0);
	if (!check_labels(&label))
		return (0);
	if (g_option & VISUAL_FLAG)
		run_visual(tab);
	debug_bin();
	debug_tab(tab);
	debug_label(&label);
	release_memory(tab);
	close(fd);
	return (1);
}
