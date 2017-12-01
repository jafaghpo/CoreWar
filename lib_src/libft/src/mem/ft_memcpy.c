/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:18:41 by iburel            #+#    #+#             */
/*   Updated: 2017/09/21 00:02:11 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	t_ulint	*ulsrc;
	t_ulint	*uldest;
	t_uchar	*ucsrc;
	t_uchar	*ucdest;

	ulsrc = (t_ulint *)src;
	uldest = (t_ulint *)dest;
	while (n > 7)
	{
		*uldest = *ulsrc;
		ulsrc++;
		uldest++;
		n -= 8;
	}
	ucsrc = (t_uchar *)ulsrc;
	ucdest = (t_uchar *)uldest;
	while (n > 0)
	{
		*ucdest = *ucsrc;
		ucsrc++;
		ucdest++;
		n--;
	}
	return (dest);
}
