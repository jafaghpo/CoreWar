/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nums.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:40:43 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/05 15:32:42 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_nums(t_args *flags, char *str)
{
	int		n;

	(void)flags;
	n = 0;
	if (!ft_isdigit(*str))
		ft_afferror("t con");
	while (ft_isdigit(*str))
	{
		n = n * 10 + *str - '0';
		str++;
	}
	if (*str || n < 1)
		ft_afferror("t con");
	return (n);
}
