/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:25:46 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/03 18:07:14 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		check_duplicate(char *name, t_lstlb *label)
{
	while (label)
	{
		if (!ft_strcmp(name, label->name))
			return (print_error(DUPLICATE_LABEL, name));
		label = label->next;
	}
	return (1);
}

static char		*duplicate_label(char *name, int size)
{
	char	*new;
	int		i;

	if (!(new = malloc(sizeof(*new) * (size + 1))))
	{
		print_error(strerror(errno));
		return (NULL);
	}
	i = 0;
	while (name[i] != LABEL_CHAR)
	{
		new[i] = name[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

t_lstlb			*add_label(t_lstlb *label, char *name, int size)
{
	t_lstlb		*new;

	if (!(new = malloc(sizeof(*new))))
	{
		print_error(strerror(errno));
		return (NULL);
	}
	new->name = duplicate_label(name, size);
	new->addr = g_bin.i - HEADER_LEN;
	if (!check_duplicate(new->name, label))
	{
		free(new->name);
		free(new);
		return (0);
	}
	if (!label)
		new->next = NULL;
	else
		new->next = label;
	return (new);
}
