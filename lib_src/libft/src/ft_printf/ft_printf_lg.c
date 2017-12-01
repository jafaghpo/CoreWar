/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:59:15 by iburel            #+#    #+#             */
/*   Updated: 2017/04/04 12:59:50 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_lg(t_ldouble nbr, t_flags *flags)
{
	t_ldouble	prec;
	int			i;

	if (nbr < 0.0001 && nbr > -0.0001)
		return (ft_printf_lg_le(nbr, flags));
	if (!(FLAGS & FPREC))
	{
		FLAGS |= FPREC;
		flags->prec = 6;
	}
	prec = 1;
	i = 0;
	while (i < flags->prec)
	{
		prec *= 10;
		i++;
	}
	if (nbr > prec || nbr < -prec)
		return (ft_printf_lg_le(nbr, flags));
	else
		return (ft_printf_lg_lf(nbr, flags));
}
