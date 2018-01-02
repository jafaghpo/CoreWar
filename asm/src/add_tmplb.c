/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tmplb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 18:07:34 by iburel            #+#    #+#             */
/*   Updated: 2017/11/21 19:10:44 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_tmplb		*add_tmplb(t_tmplb *labels, char *name, int cursor, int size, int rel)
{
	t_tmplb	*new;

	if (!(new = malloc(sizeof(*new))))
		ft_afferror(ERROR_MALLOC);
	new->name = ft_strdup(name);
	new->cursor = cursor;
	new->rel = rel;
	new->size = size;
	if (!labels)
		new->next = NULL;
	else
		new->next = labels;
	return (new);
}
