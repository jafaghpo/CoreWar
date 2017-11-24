/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cplxdiv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 21:43:37 by iburel            #+#    #+#             */
/*   Updated: 2017/03/08 21:48:20 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cplx	ft_cplxdiv(t_cplx z1, t_cplx z2)
{
	t_cplx	ret;

	ret.re = (z1.re * z2.re + z1.im * z2.im) / (z2.re * z2.re + z2.im * z2.im);
	ret.im = (z1.im * z2.re - z1.re * z2.im) / (z2.re * z2.re + z2.im * z2.im);
	return (ret);
}
