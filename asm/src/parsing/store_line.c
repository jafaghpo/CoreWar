/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 16:42:50 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/11 20:33:29 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	realloc_tab(t_tab *tab)
{
	t_tab	*dest;
	int		i;

	if (!(dest = ft_memalloc(sizeof(*dest) * (g_lines + TAB_SIZE))))
		return (print_error(0, strerror(errno)));
	i = 0;
	while (tab[i].line)
	{
		dest[i].line = tab[i].line;
		dest[i].ptr = tab[i].ptr;
		dest[i].size = tab[i].size;
		dest[i].new_line = tab[i].new_line;
		i++;
	}
	return (1);
}

int			store_line(t_tab *tab, t_tab *current)
{
	if (!(g_option & VISUAL_FLAG))
	{
		free(current->line);
		return (1);
	}
	if (!(g_lines % (sizeof(*tab) * TAB_SIZE)))
	{
		if (!realloc_tab(tab))
			return (0);
	}
	tab[g_lines].line = current->line;
	tab[g_lines].ptr = current->ptr;
	tab[g_lines].size = current->size;
	g_lines++;
	return (1);
}
