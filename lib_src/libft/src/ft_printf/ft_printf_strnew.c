/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strnew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:43:46 by iburel            #+#    #+#             */
/*   Updated: 2017/03/22 20:43:48 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_strnew(char c, int size, int fd)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(*str) * size)))
		ft_afferror("error malloc in ft_printf_strnew");
	ft_memset(str, c, size);
	ft_buf(fd, str, size);
	free(str);
	return (str);
}
