/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 19:26:52 by iburel            #+#    #+#             */
/*   Updated: 2017/04/17 19:13:50 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_blanks(t_flags *flags, t_uint u, char **str, va_list ap)
{
	(void)u;
	if (**str == '*')
	{
		flags->blanks = va_arg(ap, int);
		if (flags->blanks < 0)
		{
			FLAGS |= FSUB;
			flags->blanks *= -1;
		}
		return ;
	}
	flags->blanks = 0;
	while (**str >= '0' && **str <= '9')
	{
		flags->blanks = flags->blanks * 10 + **str - '0';
		(*str)++;
	}
	(*str)--;
}

void	ft_precs(t_flags *flags, t_uint u, char **str, va_list ap)
{
	(void)u;
	(*str)++;
	if (**str == '*')
	{
		flags->prec = va_arg(ap, int);
		if (flags->prec >= 0)
			FLAGS |= FPREC;
		return ;
	}
	FLAGS |= FPREC;
	flags->prec = 0;
	while (**str >= '0' && **str <= '9')
	{
		flags->prec = flags->prec * 10 + **str - '0';
		(*str)++;
	}
	(*str)--;
}

void	ft_fillflags(t_flags *flags, t_uint u, char **str, va_list ap)
{
	(void)str;
	(void)ap;
	FLAGS |= u;
}

void	ft_type(t_flags *flags, t_uint u, char **str, va_list ap)
{
	(void)str;
	(void)ap;
	if (u > TYPE)
		TYPE = u;
	else if (u == TYPE && u == FH)
		TYPE = FHH;
	else if (u == TYPE && u == FL)
		TYPE = FLL;
}
