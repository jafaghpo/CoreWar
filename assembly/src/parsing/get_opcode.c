/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opcode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:06:47 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/02 16:56:16 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	compare_instruction(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (!s2[i])
		return (i);
	return (0);
}

int			get_opcode(char *line, int *op)
{
	int		i;
	int		len;

	i = OP_NB - 1;
	*op = 0;
	while (i > 0)
	{
		if ((len = compare_instruction(line, g_op[i].inst)))
		{
			*op = g_op[i].opcode;
			return (len);
		}
		i--;
	}
	return (0);
}
