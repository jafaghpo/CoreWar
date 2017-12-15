/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opcode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:16:11 by iburel            #+#    #+#             */
/*   Updated: 2017/12/15 18:38:36 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_opcode(char *inst)
{
	int i;

	i = 0;
	while (g_optab[i].opcode)
	{
		if (ft_strequ(inst, g_optab[i].inst))
			return (g_optab[i].opcode);
		i++;
	}
	return (-1);
}
