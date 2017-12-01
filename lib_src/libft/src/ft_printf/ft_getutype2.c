/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getutype2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 19:29:29 by iburel            #+#    #+#             */
/*   Updated: 2017/04/20 15:07:54 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_typeuj(t_ullint *nbr)
{
	*nbr = (uintmax_t)(*nbr);
}

void	ft_typeuz(t_ullint *nbr)
{
	*nbr = (size_t)(*nbr);
}

void	ft_typeul(t_ullint *nbr)
{
	*nbr = (t_ulint)(*nbr);
}

void	ft_typeull(t_ullint *nbr)
{
	(void)nbr;
}
