/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opcode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:06:47 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/25 15:19:49 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			get_opcode(char *line, int *op)
{
	int		i;
	int		len;

	i = 1;
	*op = 0;
	while (i < OP_NB)
	{
		if ((len = word_equal(line, g_op[i].inst)))
		{
			*op = g_op[i].opcode;
			return (len);
		}
		i++;
	}
	return (0);
}
