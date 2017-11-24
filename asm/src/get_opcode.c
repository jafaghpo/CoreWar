/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opcode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:16:11 by iburel            #+#    #+#             */
/*   Updated: 2017/09/11 15:18:04 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_opcode(char *inst)
{
	int i;

	i = 0;
	while (op_tab[i].opcode)
	{
		if (ft_strequ(inst, op_tab[i].inst))
			return (op_tab[i].opcode);
		i++;
	}
	return (-1);
}
