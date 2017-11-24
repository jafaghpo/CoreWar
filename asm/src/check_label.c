/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 13:38:12 by niragne           #+#    #+#             */
/*   Updated: 2017/09/09 13:12:22 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_label(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(LABEL_CHARS, str[i]))
			return (0);
		i++;
	}
	return (1);
}
