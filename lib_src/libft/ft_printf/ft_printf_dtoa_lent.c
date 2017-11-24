/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dtoa_lent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:53:43 by iburel            #+#    #+#             */
/*   Updated: 2017/04/04 12:54:27 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init(t_ldouble *nbr, int *size, int *i, int *sub)
{
	if (*nbr < 0)
	{
		*nbr = -*nbr;
		*sub = 1;
		*size = 2;
		*i = 1;
	}
	else
	{
		*i = 0;
		*sub = 0;
		*size = 1;
	}
}

static void	ft_malloc_for_norme(char **str, int size)
{
	if (!(*str = (char *)malloc(sizeof(**str) * (size + 1))))
		ft_afferror("error malloc in ft_printf_itoa");
}

int			ft_printf_dtoa_lent(t_ldouble nbr, char **str)
{
	int			size;
	t_ldouble	div;
	int			i;
	int			sub;

	ft_init(&nbr, &size, &i, &sub);
	div = 1;
	while (div <= nbr / 10)
	{
		div *= 10;
		size += 1;
	}
	ft_malloc_for_norme(str, size + 1);
	if (sub)
		(*str)[0] = '-';
	while (div >= 1)
	{
		(*str)[i] = (int)(nbr / div) + '0';
		while (nbr >= div)
			nbr -= div;
		div /= 10;
		i++;
	}
	(*str)[i] = '\0';
	return (size);
}
