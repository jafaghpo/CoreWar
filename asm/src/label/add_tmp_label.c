/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tmp_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 19:19:00 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/15 23:42:16 by jafaghpo         ###   ########.fr       */
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

	if (!(new = malloc(sizeof(*new) * size)))
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
	if (!(g_option & VISUAL_FLAG))
		new->name = duplicate_tmp_label(tmp.name, arg_len(tmp.name));
	else
		new->name = tmp.name;
	new->cursor = g_bin.i + tmp.cursor;
	new->size = tmp.size;
	new->rel = g_bin.i - HEADER_LEN;
	if (!label)
		new->next = NULL;
	else
		new->next = label;
	return (new);
}
