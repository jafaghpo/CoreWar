/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:25:46 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/13 01:36:56 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_lstlb			*add_label(t_lstlb *label, char *name, int size)
{
	t_lstlb		*new;

	if (!(new = malloc(sizeof(*new))))
	{
		print_error(strerror(errno));
		return (NULL);
	}
	if (!(g_option & VISUAL_FLAG))
		new->name = duplicate_label(name, size);
	else
		new->name = name;
	new->addr = g_bin.i - HEADER_LEN;
	if (!label)
		new->next = NULL;
	else
		new->next = label;
	return (new);
}
