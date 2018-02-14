/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 16:15:45 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/16 18:20:58 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		add_argument(int addr, int i, int len)
{
	if (len == 1)
	{
		g_bin.data[i + 0] = (t_uint8)(addr >> 8);
		g_bin.data[i + 1] = (t_uint8)(addr >> 0);
	}
	else
	{
		g_bin.data[i + 0] = (t_uint8)(addr >> 24);
		g_bin.data[i + 1] = (t_uint8)(addr >> 16);
		g_bin.data[i + 2] = (t_uint8)(addr >> 8);
		g_bin.data[i + 3] = (t_uint8)(addr >> 0);
	}
}

int				check_labels(t_label *label)
{
	t_tmplb		*tmp;
	int			error;
	int			addr;

	tmp = label->tmp;
	addr = 0;
	while (tmp)
	{
		if (tmp->name[0])
		{
			addr = eval_expr(tmp->name, label, &error, tmp->rel);
			if (error)
				return (print_error(UNDEF_LABEL, tmp->name));
			add_argument(addr, tmp->cursor, tmp->size);
		}
		tmp = tmp->next;
	}
	return (1);
}
