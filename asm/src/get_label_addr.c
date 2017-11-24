/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:15:28 by iburel            #+#    #+#             */
/*   Updated: 2017/10/03 12:42:11 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_label_addr(char *str, t_label *labels)
{
	t_lstlb	*tmp;

	tmp = labels->lst;
	while (tmp)
	{
		if (!ft_strcmp(str, tmp->name))
			return (tmp->addr);
		tmp = tmp->next;
	}
	return (-1);
}
