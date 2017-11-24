/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 14:53:21 by iburel            #+#    #+#             */
/*   Updated: 2017/09/13 12:46:28 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_lstlb		*add_label(t_lstlb *labels, char *name, int addr)
{
	t_lstlb	*new;

	if (!(new = malloc(sizeof(*new))))
		ft_afferror(ERROR_MALLOC);
	new->name = ft_strdup(name);
	new->addr = addr;
	if (!labels)
		new->next = NULL;
	else
		new->next = labels;
	return (new);
}
