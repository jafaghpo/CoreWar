/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:10:37 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/02 16:48:46 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			word_equal(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (!s1[i])
		return (i);
	if (s1[i] != ' ' && s1[i] != '\t' && s1[i] != SEPARATOR_CHAR)
		return (0);
	if (s1[i] == SEPARATOR_CHAR)
		i++;
	while (s1[i] == ' ' || s1[i] == '\t')
		i++;
	return (i);
}
