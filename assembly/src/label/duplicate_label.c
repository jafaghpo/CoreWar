/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:32:09 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/22 15:29:00 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*duplicate_label(char *name, int size)
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
