/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:26:07 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/19 20:59:58 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		debug_tab(t_tab *tab)
{
	int		i;
	int		j;
	int		fd;

	i = 0;
	fd = open("/dev/ttys001", O_WRONLY);
	dprintf(fd, "\ntable");
	while (i < g_lines)
	{
		dprintf(fd, "line n%d: [%s]\n", i, tab[i].line);
		j = 0;
		dprintf(fd, "ptr: ");
		while (j < tab[i].size)
			dprintf(fd, "%.2X ", tab[i].ptr[j++]);
		dprintf(fd, "size: [%d]\n", tab[i].size);
		i++;
	}
}

void		debug_tmplb(t_tmplb *label)
{
	t_tmplb		*tmp;

	tmp = label;
	ft_printf("\nundefined labels:\n");
	while (tmp)
	{
		ft_printf("name = [%s] cursor = [%d] size = [%d] rel = [%d]\n",
		tmp->name, tmp->cursor, tmp->size, tmp->rel);
		tmp = tmp->next;
	}
}

void		debug_label(t_lstlb *label)
{
	t_lstlb		*tmp;

	tmp = label;
	ft_printf("\ndefined labels:\n");
	while (tmp)
	{
		ft_printf("name = [%s] addr = [%d]\n", tmp->name, tmp->addr);
		tmp = tmp->next;
	}
}

void		debug_inst(t_inst *inst)
{
	int		i;

	i = 0;
	ft_printf("instruction %s: ", g_op[inst->data[0]].inst);
	while (i < inst->size)
	{
		ft_printf("%.2X ", g_bin.data[i + g_bin.i]);
		i++;
	}
	ft_printf("\n\n");
}
