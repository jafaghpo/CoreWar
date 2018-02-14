/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 18:56:24 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/15 17:03:58 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_next_arg(char **str)
{
	while (**str != ' ' && **str != '\t' && **str != SEPARATOR_CHAR && **str)
		(*str)++;
	ft_delspace(str);
	if (**str == COMMENT_CHAR || !**str)
		return (1);
	if (**str == SEPARATOR_CHAR)
	{
		(*str)++;
		ft_delspace(str);
	}
	else
		return (0);
	return (1);
}
