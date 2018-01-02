/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 22:19:33 by iburel            #+#    #+#             */
/*   Updated: 2017/12/16 18:01:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     pf_itoa(char *str, t_int64 n)
{
    int     size;
    t_int64 div;
    int     i;

    size = 1;
    div = -1;
    while (div >= n / 10)
    {
        div *= 10;
        size++;
    }
    i = 0;
    while (div < 0)
    {
        str[i] = n / div + '0';
        n %= div;
        div /= 10;
        i++;
    }
    return (size);
}