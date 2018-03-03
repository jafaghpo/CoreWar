/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 16:26:33 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/03 18:48:27 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			print_error(const char *msg, ...)
{
	va_list	ap;

	va_start(ap, msg);
	if (g_option & VISUAL_FLAG)
		ft_vsprintf(g_error, (char*)msg, ap);
	else
	{
		ft_dprintf(2, "asm: ");
		ft_dprintf(2, RED);
		ft_vdprintf(2, (char*)msg, ap);
		ft_dprintf(2, "\n");
		ft_dprintf(2, RES);
		va_end(ap);
	}
	return (0);
}
