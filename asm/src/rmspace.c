/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmspace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:13:13 by iburel            #+#    #+#             */
/*   Updated: 2017/09/18 14:20:00 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*rmspace(char *str)
{
	int		len;
	char	*new;
	char	*tmp;

	len = strlen(str);
	if (!(new = malloc(sizeof(*new) * (len + 1))))
		return (NULL);
	tmp = new;
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
		{
			*tmp = *str;
			tmp++;
		}
		str++;
	}
	*tmp = 0;
	return (new);
}
