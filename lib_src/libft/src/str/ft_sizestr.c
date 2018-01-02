/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 15:45:39 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 19:27:52 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int		ft_sizestr(char *str)
{
	int		ret;

	ret = 0;
	while (*str)
	{
		ret += *str;
		str++;
	}
	return (ret);
}
