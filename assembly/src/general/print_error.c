/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 16:26:33 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/19 16:17:10 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			print_error(const char *msg, ...)
{
	va_list	ap;

	if (g_option & VISUAL_FLAG)
	{
		g_option &= ~(VISUAL_FLAG);
		endwin();
	}
	va_start(ap, msg);
	dprintf(2, "asm: ");
	vdprintf(2, msg, ap);
	dprintf(2, "\n");
	va_end(ap);
	return (0);
}
