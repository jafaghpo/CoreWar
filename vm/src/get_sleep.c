/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:59:42 by niragne           #+#    #+#             */
/*   Updated: 2018/02/18 18:43:51 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_sleep(t_args *flags, char *str)
{
	t_uint32	n;

	n = 0;
	flags->dump = 1;
	if (!ft_isdigit(*str))
		ft_afferror("error bad number after -s\n");
	while (ft_isdigit(*str))
	{
		n = n * 10 + *str - '0';
		str++;
	}
	if (*str)
		ft_afferror("error bad number after -s\n");
	if (n < 1 || n > 20000)
		ft_afferror("speed < 1 or > 20000\n");
	g_sleep = 1000000.0 / (float)n;
	return (-1);
}
