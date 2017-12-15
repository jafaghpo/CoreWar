/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:32:35 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/12/15 18:39:42 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

int			print_error(char *msg, const char function[], char *file, int line)
{
	if (!msg)
	{
		ft_printf("%fd%s: %s in %s (%s:%d)\n", 2, EXEC_NAME, strerror(errno),
		function, file, line);
	}
	else
	{
		ft_printf("%fd%s: %s in %s (%s:%d)\n", 2, EXEC_NAME, msg,
		function, file, line);
	}
	return (0);
}
