/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:59:42 by niragne           #+#    #+#             */
/*   Updated: 2018/01/05 18:02:08 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	    get_sleep(t_args *flags, char *str)
{
    t_uint32     n;

    n = 0;
    flags->dump = 1;
    if (!ft_isdigit(*str))
        ft_afferror("t con");
    while (ft_isdigit(*str))
    {
        n = n * 10 + *str - '0';
        str++;
    }
    if (*str)
        ft_afferror("t con");
    g_sleep = n;
    return (-1);
}