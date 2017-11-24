/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 01:23:21 by iburel            #+#    #+#             */
/*   Updated: 2017/03/25 14:17:16 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sizechar(wchar_t c)
{
	if (!(c >> (7 + (MB_CUR_MAX == 1))))
		return (1);
	else if (!(c >> 11))
		return (2);
	else if (!(c >> 16))
		return (3);
	else if (!(c >> 21))
		return (4);
	return (-1);
}

size_t		ft_wstrlen(const wchar_t *str)
{
	size_t		i;
	size_t		size;

	size = 0;
	i = 0;
	while (str[i])
	{
		size += ft_sizechar(str[i]);
		i++;
	}
	return (size);
}
