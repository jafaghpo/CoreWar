/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tmp_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 19:19:00 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/24 17:00:42 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	arg_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] != SEPARATOR_CHAR && line[i])
		i++;
	while (line[i - 1] == ' ' || line[i - 1] == '\t')
		i--;
	return (i);
}

static char	*duplicate_tmp_label(char *name, int size)
{
	char	*new;
	int		i;

	if (!(new = malloc(sizeof(*new) * (size + 1))))
	{
		print_error(strerror(errno));
		return (NULL);
	}
	i = 0;
	while (i != size)
	{
		new[i] = name[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

t_tmplb		*add_tmp_label(t_tmplb *label, t_tmplb tmp)
{
	t_tmplb		*new;

	if (!(new = malloc(sizeof(*new))))
	{
		print_error(strerror(errno));
		return (NULL);
	}
	new->name = duplicate_tmp_label(tmp.name, arg_len(tmp.name));
	new->cursor = g_bin.i + tmp.cursor;
	new->size = tmp.size;
	new->rel = g_bin.i - HEADER_LEN;
	if (!label)
		new->next = NULL;
	else
		new->next = label;
	return (new);
}
