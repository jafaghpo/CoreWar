/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:19:39 by iburel            #+#    #+#             */
/*   Updated: 2017/03/25 13:43:26 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putchar_fd(wchar_t c, int fd)
{
	unsigned int	octet;

	if (!(c >> (7 + (MB_CUR_MAX == 1))))
		return (write(fd, &c, 1));
	else if (!(c >> 11))
	{
		octet = (((c & 0x3f) << 8) | (c >> 6)) | 0x80c0;
		return (write(fd, &octet, 2));
	}
	else if (!(c >> 16))
	{
		octet = (((c & 0x3f) << 16) | (((c >> 6) & 0x3f) << 8)
				| (c >> 12)) | 0x8080e0;
		return (write(fd, &octet, 3));
	}
	else if (!(c >> 21))
	{
		octet = (((((c & 0x3f) << 24) | (((c >> 6) & 0x3f) << 16))
				| (((c >> 12) & 0x3f) << 8)) | (c >> 18)) | 0x808080f0;
		return (write(fd, &octet, 4));
	}
	return (-1);
}
