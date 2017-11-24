/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlabels.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 17:18:50 by iburel            #+#    #+#             */
/*   Updated: 2017/09/11 18:17:38 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	putlabels(t_label *labels)
{
	t_lstlb	*lst_tmp;
	t_tmplb	*tmp_tmp;

	ft_printf("liste des labels declares\n\n");
	lst_tmp = labels->lst;
	while (lst_tmp)
	{
		ft_printf("name : %s\n", lst_tmp->name);
		ft_printf("addr : %d\n\n", lst_tmp->addr);
		lst_tmp = lst_tmp->next;
	}
	ft_printf("\nliste des labels pas encore declares\n\n");
	tmp_tmp = labels->tmp;
	while (tmp_tmp)
	{
		ft_printf("name : %s\n", tmp_tmp->name);
		ft_printf("cursor : %d\n", tmp_tmp->cursor);
		ft_printf("size : %d\n\n", tmp_tmp->size);
		tmp_tmp = tmp_tmp->next;
	}
}
