/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dtoa_g_f.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 23:44:56 by iburel            #+#    #+#             */
/*   Updated: 2017/03/28 00:00:01 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_dtoa_g_f(double nbr, t_flags *flags, char **str)
{
	int		size;
	int		i;
	char	*ent;
	char	*dec;

	size = ft_printf_dtoa_ent(nbr, &ent);
	flags->prec += (!(FLAGS & FPREC)) * 6 - size + (nbr < 0);
	if (!flags->prec)
	{
		*str = ent;
		return (size);
	}
	if (!(dec = (char *)malloc(sizeof(*dec) * (flags->prec + 3))))
		ft_afferror("error malloc in ft_printf_dtoa_f");
	dec[0] = '.';
	i = 1;
	while (i < flags->prec + 2)
	{
		nbr = (nbr - (t_llint)nbr) * 10 * (-2 * (nbr < 0) + 1);
		dec[i] = (t_llint)(nbr) + '0';
		i++;
	}
	dec[i] = '\0';
	*str = ft_strjoin_free(ent, dec, 'L' + 'R');
	return (size + flags->prec + 1);
}
