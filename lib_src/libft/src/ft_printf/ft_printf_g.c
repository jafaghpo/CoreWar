/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_g.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 16:05:51 by iburel            #+#    #+#             */
/*   Updated: 2017/04/16 21:16:12 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_g(t_flags *flags, va_list ap)
{
	double	prec;
	int		i;
	double	nbr;

	if (FLAGS & FL2)
		return (ft_printf_lg(va_arg(ap, t_ldouble), flags));
	nbr = va_arg(ap, double);
	if (nbr < 0.0001 && nbr > -0.0001)
		return (ft_printf_g_e(nbr, flags));
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
		return (ft_printf_g_e(nbr, flags));
	else
		return (ft_printf_g_f(nbr, flags));
}
