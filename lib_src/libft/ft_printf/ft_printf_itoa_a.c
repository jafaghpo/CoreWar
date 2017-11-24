/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:04:10 by iburel            #+#    #+#             */
/*   Updated: 2017/03/28 17:17:54 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init(int *nbr, int *size, int *i, int *sub)
{
	*i = 1;
	*size = 2;
	if (*nbr < 0)
		*sub = 1;
	else
	{
		*nbr = -*nbr;
		*sub = 0;
	}
}

int			ft_printf_itoa_a(int nbr, char *str)
{
	int		size;
	int		div;
	int		i;
	int		sub;

	ft_init(&nbr, &size, &i, &sub);
	div = -1;
	while (div >= nbr / 10)
	{
		div *= 10;
		size += 1;
	}
	if (sub)
		str[0] = '-';
	else
		str[0] = '+';
	while (div < 0)
	{
		str[i] = nbr / div + '0';
		nbr %= div;
		div /= 10;
		i++;
	}
	return (size);
}
