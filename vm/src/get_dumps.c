/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dumps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:40:43 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/04 14:49:47 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	    get_dumps(t_args *flags, char *str)
{
    int     n;

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
    flags->dumps = n;
    return (-1);
}