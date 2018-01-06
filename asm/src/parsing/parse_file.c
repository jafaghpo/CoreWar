/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:54:54 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/06 16:58:55 by jafaghpo         ###   ########.fr       */
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

int				parse_file(char *name)
{
	t_tab		*tab;
	t_label		label;
	int			fd;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (print_error(0, ERROR_DIR, name, strerror(errno)));
	if (!(tab = ft_memalloc(sizeof(*tab) * BSIZE)))
		return (print_error(0, ERROR_MEM, strerror(errno), "str"));
	if (!(g_bin.data = ft_memalloc(sizeof(*g_bin.data) * BSIZE)))
		return (print_error(0, ERROR_MEM, strerror(errno), "g_bin.data"));
	if (!tokenize_file(tab, &label, fd))
		return (0);
	if (!check_tmp_labels(&label))
		return (0);
	if (g_option & VISUAL_FLAG)
		run_visual(tab);
	release_memory(tab);
	close(fd);
	return (1);
}
