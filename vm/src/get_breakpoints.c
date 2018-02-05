/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_breakpoints.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:02:19 by niragne           #+#    #+#             */
/*   Updated: 2018/02/05 15:15:40 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			get_breakpoints(t_args *flags, char *str, char **av, int *i)
{
	int		n;
	int		tmp;

	n = 1;
	(void)flags;
	(void)str;
	while (av[n] && (tmp = ft_atoi(av[n])))
	{
		g_flags.breakpoints[g_flags.nb_breakpoints] = tmp;
		g_flags.nb_breakpoints++;
		if (g_flags.nb_breakpoints > MAX_BREAKPOINTS)
			ft_afferror(ERROR_NB_BREAKPOINT);
		if (tmp < 0)
			ft_afferror(ERROR_BREAKPOINT);
		n++;
	}
	(*i) += n - 2;
	if (n == 1)
		ft_afferror(ERROR_BREAKPOINT);        
	return (-1);
}
