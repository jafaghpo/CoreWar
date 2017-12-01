/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:41:14 by iburel            #+#    #+#             */
/*   Updated: 2017/04/16 21:17:34 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_initopt(int opt[5], int size, t_flags *flags, int zero)
{
	PREC = flags->prec - size;
	HASHTAG = ((FLAGS & FHT) && !zero) * 2;
	ZERO = ((FLAGS & FPREC) && (flags->prec == 0) && zero);
	BLANKS = flags->blanks - size - PREC * (PREC > 0) -
		HASHTAG + ZERO;
	if (!(FLAGS & FPREC) && (FLAGS & FZE) && !(FLAGS & FSUB))
	{
		PREC = flags->blanks - size - HASHTAG;
		BLANKS = 0;
	}
}

static int	ft_addopt(int size, char *str, t_flags *flags, int zero)
{
	int		opt[5];

	ft_initopt(opt, size, flags, zero);
	if (!(FLAGS & FSUB) && BLANKS > 0)
		ft_printf_strnew(' ', BLANKS, FD);
	if (HASHTAG && !zero && !(FLAGS & FMAJ))
		ft_buf(FD, "0x", 2);
	else if (HASHTAG && !zero)
		ft_buf(FD, "0X", 2);
	if (PREC > 0)
		ft_printf_strnew('0', PREC, FD);
	if (ZERO)
		size -= 1;
	else
		ft_buf(FD, str, size);
	if ((FLAGS & FSUB) && BLANKS > 0)
		ft_printf_strnew(' ', BLANKS, FD);
	return (size + PREC * (PREC > 0) +
			BLANKS * (BLANKS > 0) + HASHTAG);
}

int			ft_printf_x(t_flags *flags, va_list ap)
{
	int			size;
	char		*str;
	t_ullint	nbr;

	nbr = va_arg(ap, t_ullint);
	ft_getutype(TYPE, &nbr);
	size = ft_printf_itoa_base(nbr, 16, &str, (FLAGS & FMAJ) > 0);
	size = ft_addopt(size, str, flags, nbr == 0);
	free(str);
	return (size);
}
