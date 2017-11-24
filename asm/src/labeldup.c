/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labeldup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 12:38:50 by iburel            #+#    #+#             */
/*   Updated: 2017/09/13 12:43:23 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*labeldup(char *label)
{
	char	*ret;
	int		i;

	i = 0;
	while (label[i] != ' ' && label[i] != '\t' &&
			label[i] != '+' && label[i] != '-' && label[i])
		i++;
	if (!(ret = malloc(sizeof(*ret) * (i + 1))))
		ft_afferror(ERROR_MALLOC);
	ft_strncpy(ret, label, i);
	ret[i] = 0;
	return (ret);
}
