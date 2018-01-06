/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 19:55:32 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/06 17:50:40 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			g_lines = 0;

int			tokenize_file(t_tab *tab, t_label *label, int fd)
{
	t_tab	current;
	char	*line;
	int		ret;
	short	head_state;

	label = (t_label*){0};
	head_state = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			return (print_error(0, strerror(errno)));
		current = (t_tab){line, ft_strlen(line), NULL, 0};
		ft_delspace(&line);
		if (!tokenize_line(line, &current, label))
			return (0);
		store_bin_line(tab, &current, g_lines);
		g_lines++;
	}
	return (1);
}
