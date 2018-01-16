/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:54:54 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/16 18:20:19 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_buf			g_bin = {NULL, BUFF_SIZE, 0};
int				g_lines = 0;

static void		delete_label(t_label *label)
{
	t_tmplb		*tmp;
	t_lstlb		*lst;

	while (label->lst)
	{
		lst = label->lst->next;
		if (!(g_option & VISUAL_FLAG))
			free(label->lst->name);
		free(label->lst);
		label->lst = lst;
	}
	while (label->tmp)
	{
		tmp = label->tmp->next;
		if (!(g_option & VISUAL_FLAG))
			free(label->tmp->name);
		free(label->tmp);
		label->tmp = tmp;
	}
}

static void		release_memory(t_tab *tab, t_label *label)
{
	int		i;

	i = 0;
	delete_label(label);
	if (!(g_option & VISUAL_FLAG))
		return ;
	while (tab[i].line)
	{
		ft_memdel((void**)&tab[i].line);
		i++;
	}
	ft_memdel((void**)&tab);
}

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
	debug_tab(tab);
	release_memory(tab, &label);
	close(fd);
	return (1);
}
