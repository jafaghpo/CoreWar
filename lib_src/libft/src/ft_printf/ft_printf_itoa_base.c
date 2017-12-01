/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:40:24 by iburel            #+#    #+#             */
/*   Updated: 2017/03/22 20:43:23 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_getchar(int n, int maj)
{
	if (n < 10)
		return (n + '0');
	return (n - 10 + 'a' - 32 * maj);
}

int			ft_printf_itoa_base(t_ullint nbr, int base, char **str, int maj)
{
	int			size;
	t_ullint	div;
	int			i;

	size = 1;
	div = 1;
	while (div <= nbr / base)
	{
		div *= base;
		size += 1;
	}
	if (!(*str = (char *)malloc(sizeof(**str) * (size + 1))))
		ft_afferror("error malloc in ft_printf_itoa_base");
	i = 0;
	while (div > 0)
	{
		(*str)[i] = ft_getchar(nbr / div, maj);
		nbr %= div;
		div /= base;
		i++;
	}
	(*str)[i] = '\0';
	return (size);
}
