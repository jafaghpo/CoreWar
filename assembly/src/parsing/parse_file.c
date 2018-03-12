/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:54:54 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/11 11:35:57 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		magic_number(void)
{
	g_bin.data[0] = (t_uint8)(COREWAR_EXEC_MAGIC >> 24);
	g_bin.data[1] = (t_uint8)(COREWAR_EXEC_MAGIC >> 16);
	g_bin.data[2] = (t_uint8)(COREWAR_EXEC_MAGIC >> 8);
	g_bin.data[3] = (t_uint8)(COREWAR_EXEC_MAGIC >> 0);
	g_bin.i = 4;
}

int				parse_file(char *name, t_visual *win, t_tab *tab)
{
	t_label		label;
	t_file		*file;

	if (!(g_option & VISUAL_FLAG))
		ft_printf(COMPILATION_START, name);
	ft_bzero((void*)g_error, ERROR_SIZE);
	if (!(file = ft_fopen(name, O_RDONLY)))
		return (print_error(UNKNOWN_FILE, name, strerror(errno)));
	ft_bzero((void*)&label, (size_t)sizeof(label));
	if (!g_bin.data && !(g_bin.data = ft_memalloc(sizeof(*g_bin.data) * BSIZE)))
		return (print_error(strerror(errno)));
	if (!get_header(tab, file, win) || !get_inst(tab, &label, file, win)
	|| !check_labels(&label))
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
