/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 16:26:33 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/03 18:28:17 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			print_error(char *msg)
{
	if (!msg)
		dprintf(2, "asm: %s\n", strerror(errno));
	else
		dprintf(2, "asm: %s\n", msg);
	return (0);
}
