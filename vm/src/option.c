/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:40:43 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/10/21 15:50:38 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	get_dumps(t_args *flags, char **av, int *i, int ac)
{
	flags->dump = 1;
	if (*i + 1 >= ac)
		ft_afferror("invalid dumps");
	if ((flags->dumps = ft_atoi(av[*i + 1])) < 1)
		ft_afferror("invalid dumps");
	(*i)++;
}

int		get_nums(t_args *flags, char **av, int *i, int ac)
{
	int n;
	int j;

	(void)flags;
	n = 0;
	j = 0;
	(*i)++;
	if (*i >= ac || !av[*i][0])
		ft_afferror(ERROR_INVALID_ARGUMENT);
	while (ft_isdigit(av[*i][j]))
	{
		n = n * 10 + av[*i][j] - '0';
		j++;
	}
	if (av[*i][j])
		ft_afferror(ERROR_INVALID_ARGUMENT);
	if (n > MAX_PLAYERS || n == 0)
		ft_afferror(ERROR_CHAMP_POS);
	(*i)++;
	return (n);
}
