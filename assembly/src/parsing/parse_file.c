/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:54:54 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/22 16:56:39 by jafaghpo         ###   ########.fr       */
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
		ft_memdel((void**)&label->lst->name);
		ft_memdel((void**)&label->lst);
		label->lst = lst;
	}
	while (label->tmp)
	{
		tmp = label->tmp->next;
		ft_memdel((void**)&label->tmp->name);
		ft_memdel((void**)&label->tmp);
		label->tmp = tmp;
	}
}

int				parse_file(char *name, t_visual *win, t_tab *tab)
{
	t_label		label;
	t_file		*file;

	if (!(g_option & VISUAL_FLAG))
		ft_printf("\nCompiling %s\n", name);
	if (!(file = ft_fopen(name, O_RDONLY)))
		return (print_error(UNKNOWN_FILE, name, strerror(errno)));
	ft_bzero((void*)&label, (size_t)sizeof(label));
	if (!g_bin.data && !(g_bin.data = ft_memalloc(sizeof(*g_bin.data) * BSIZE)))
		return (print_error(strerror(errno)));
	if (!get_header(tab, file, win) || !get_inst(tab, &label, file, win) ||
		!check_labels(&label))
	{
		delete_label(&label);
		free(file);
		return (0);
	}
	if (g_lines != 0 && (g_option & VISUAL_FLAG))
		run_visual(tab, win);
	delete_label(&label);
	close(file->fd);
	free(file);
	return (1);
}
