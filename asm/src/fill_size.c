/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 18:14:10 by iburel            #+#    #+#             */
/*   Updated: 2017/09/13 18:26:46 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		fill_size(t_parse *parse)
{
	int		i;

	i = 0;
	while (i < parse->nb)
	{
		if (!(parse->size[i] = arglen(parse->ptr[i])))
			return (puterror(ERROR_SYNTAX_SEPARATOR, 0));
		parse->ptr[i][parse->size[i]] = 0;
		i++;
	}
	return (1);
}
