/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 18:56:24 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/22 17:09:04 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_next_arg(char **str)
{
	while (**str != SEPARATOR_CHAR && **str != COMMENT_CHAR && **str)
		(*str)++;
	if (**str == SEPARATOR_CHAR)
	{
		(*str)++;
		ft_delspace(str);
	}
}
