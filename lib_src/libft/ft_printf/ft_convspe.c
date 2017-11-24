/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convspe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 19:26:16 by iburel            #+#    #+#             */
/*   Updated: 2017/04/16 21:18:15 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_2(t_flags *flags, va_list ap)
{
	(void)ap;
	(void)flags;
	return (-2);
}

int		ft_printf_3(t_flags *flags, va_list ap)
{
	(void)ap;
	(void)flags;
	return (-3);
}

int		ft_printf_per(t_flags *flags, va_list ap)
{
	(void)ap;
	return (ft_printf_ind('%', flags));
}
