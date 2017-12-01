/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:05:50 by iburel            #+#    #+#             */
/*   Updated: 2017/04/04 13:24:38 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_norme(t_flags *flags, int *nb)
{
	FD = 1;
	*nb = 0;
}

int			ft_printf(char *str, ...)
{
	t_flags	flags;
	va_list	ap;
	int		nb;

	va_start(ap, str);
	ft_norme(&flags, &nb);
	while (*str)
	{
		if (*str == '%')
		{
			if ((nb += ft_per(&str, &flags, ap)) == -1)
				return (-1);
		}
		else if (*str == '{')
			nb += ft_color(&str, flags.fd);
		else
		{
			ft_buf(flags.fd, str, 1);
			nb++;
		}
		str++;
	}
	va_end(ap);
	ft_buf(flags.fd, NULL, -1);
	return (nb);
}
