/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dumps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:40:43 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/18 18:07:01 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_dumps(t_args *flags, char *str)
{
	int		n;

	n = 0;
	flags->dump = 1;
	if (!ft_isdigit(*str))
		ft_afferror("error bad number after -d\n");
	while (ft_isdigit(*str))
	{
		n = n * 10 + *str - '0';
		str++;
	}
	if (*str)
		ft_afferror("error bad number after -d\n");
	flags->dumps = n;
	return (-1);
}
