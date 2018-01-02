/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:18:41 by iburel            #+#    #+#             */
/*   Updated: 2017/12/03 17:51:41 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_memcpy(void *dest, void *src, int len)
{
    while (len >= 8)
    {
        *((t_uint64 *)dest) = *((t_uint64 *)src);
        dest = (void *)((t_uint64 *)dest + 1);
        src = (void *)((t_uint64 *)src + 1);
        len -= 8;
    }
    while (len > 0)
    {
        *((t_uint8 *)dest) = *((t_uint8 *)src);
        dest = (void *)((t_uint8 *)dest + 1);
        src = (void *)((t_uint8 *)src + 1);
        len -= 1;
    }
}
