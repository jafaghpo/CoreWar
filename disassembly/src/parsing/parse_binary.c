/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 18:34:58 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/08 19:46:37 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

int			parse_binary(char *path, t_visual *win, t_tab *tab)
{
	int		fd;

	if (!g_asm.data)
	{
		if (!(g_asm.data = ft_memalloc(sizeof(*g_asm.data) * g_asm.size)))
			return (print_error(strerror(errno)));
	}
	if (!g_bin.data)
	{
		if (!(g_bin.data = ft_memalloc(sizeof(*g_bin.data) * g_bin.size)))
			return (print_error(strerror(errno)));
	}
	if (!get_name(win, tab) || !get_comment(win, tab) || !get_inst(win, tab))
		return (0);
	if ((g_option & VISUAL_FLAG) && g_lines != 0)
		run_visual(tab, win);
	if ((fd = open(path, O_TRUNC | O_CREAT | O_WRONLY, 0644)) == -1)
		return (print_error(UNKNOWN_FILE, path, strerror(errno)));
	write(fd, g_asm.data, g_asm.i);
	close(fd);
	if (!(g_option & VISUAL_FLAG))
		ft_printf(COMPILATION_END, path);
	return (1);
}
