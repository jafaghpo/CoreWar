/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 15:25:58 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/11 14:30:58 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		reset_buffer(void)
{
	if (g_bin.data)
	{
		g_state = 0;
		if (g_bin.i < HEADER_LEN)
			ft_bzero((void*)g_bin.data, HEADER_LEN);
		else
			ft_bzero((void*)g_bin.data, g_bin.i);
		g_bin.i = 0;
	}
}
