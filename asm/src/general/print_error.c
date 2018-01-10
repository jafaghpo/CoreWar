/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 16:26:33 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/10 17:53:19 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			print_error(int usage, const char *msg, ...)
{
	va_list	ap;

	if (msg)
	{
		va_start(ap, msg);
		dprintf(2, "asm: ");
		vdprintf(2, msg, ap);
		dprintf(2, "\n");
		if (usage)
			dprintf(2, ERROR_USAGE);
		va_end(ap);
	}
	else
	{
		if (usage)
			dprintf(2, ERROR_USAGE);
	}
	return (0);
}
