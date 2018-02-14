/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 18:21:03 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/16 16:28:40 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		store_argument(t_inst *inst, int n, int size)
{
	if (size)
	{
		inst->data[inst->size + 0] = (char)(n >> 8);
		inst->data[inst->size + 1] = (char)(n >> 0);
		inst->size += 2;
	}
	else
	{
		inst->data[inst->size + 0] = (char)(n >> 24);
		inst->data[inst->size + 1] = (char)(n >> 16);
		inst->data[inst->size + 2] = (char)(n >> 8);
		inst->data[inst->size + 3] = (char)(n >> 0);
		inst->size += 4;
	}
}
