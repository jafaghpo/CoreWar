/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:54:54 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/30 13:43:02 by jafaghpo         ###   ########.fr       */
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

int				parse_file(char *name, t_visual *win, t_tab *tab)
{
	t_label		label;
	int			fd;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (print_error(UNKNOWN_FILE, name, strerror(errno)));
	label = (t_label){0, 0};
	if (!g_bin.data)
	{
		if (!(g_bin.data = ft_memalloc(sizeof(*g_bin.data) * BUFF_SIZE)))
			return (print_error(strerror(errno)));
	}
	if (!get_header(tab, fd, win) || !get_instructions(tab, &label, fd, win))
		return (0);
	if (!check_labels(&label))
		return (0);
	if (g_option & VISUAL_FLAG)
		run_visual(tab, win);
	delete_label(&label);
	close(fd);
	return (1);
}
