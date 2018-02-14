/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:26:07 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/16 18:18:33 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		debug_tab(t_tab *tab)
{
	int		i;
	int		j;

	i = 0;
	ft_printf("\ntable:\n");
	while (i < g_lines)
	{
		if (tab[i].new_line)
			ft_printf("\n");
		ft_printf("line n%d: [%s]\n", i, tab[i].line);
		j = 0;
		ft_printf("ptr: ");
		while (j < tab[i].size)
			ft_printf("%.2X ", tab[i].ptr[j++]);
		ft_printf("size: [%d] new_line: [%d]\n", tab[i].size, tab[i].new_line);
		i++;
	}
}

void		debug_tmplb(t_label *label)
{
	t_tmplb		*tmp;

	tmp = label->tmp;
	ft_printf("\nundefined labels:\n");
	while (tmp)
	{
		ft_printf("name = [%s] cursor = [%d] size = [%d] rel = [%d]\n",
		tmp->name, tmp->cursor, tmp->size, tmp->rel);
		tmp = tmp->next;
	}
}

void		debug_label(t_label *label)
{
	t_lstlb		*tmp;

	tmp = label->lst;
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
