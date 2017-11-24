/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tmplb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 18:07:34 by iburel            #+#    #+#             */
/*   Updated: 2017/09/29 15:32:10 by iburel           ###   ########.fr       */
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
