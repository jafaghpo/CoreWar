/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:11:27 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/24 17:11:36 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		delete_label(t_label *label)
{
	t_tmplb		*tmp;
	t_lstlb		*lst;

	while (label->lst)
	{
		lst = label->lst->next;
		free(label->lst->name);
		free(label->lst);
		label->lst = lst;
	}
	while (label->tmp)
	{
		tmp = label->tmp->next;
		free(label->tmp->name);
		free(label->tmp);
		label->tmp = tmp;
	}
}
