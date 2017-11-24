/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:19:15 by iburel            #+#    #+#             */
/*   Updated: 2016/11/03 10:19:16 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	t_ulint	*tmp1;
	t_uchar	*tmp2;
	t_ulint	lc;

	if ((lc = (t_uchar)c))
	{
		lc = (lc << 8) | lc;
		lc = (lc << 16) | lc;
		lc = (lc << 32) | lc;
	}
	tmp1 = (t_ulint *)ptr;
	while (n > 7)
	{
		*tmp1 = lc;
		tmp1++;
		n -= 8;
	}
	tmp2 = (t_uchar *)tmp1;
	while (n > 0)
	{
		*tmp2 = (t_uchar)c;
		tmp2++;
		n--;
	}
	return (ptr);
}
