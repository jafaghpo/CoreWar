/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:43:25 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/08 19:45:55 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

void			reset_buffer(void)
{
	if (g_bin.data)
	{
		free(g_bin.data);
		g_bin.size = 0;
		g_bin.i = 0;
	}
	if (g_asm.data)
	{
		ft_bzero((void*)g_asm.data, g_asm.size);
		g_asm.i = 0;
	}
}
