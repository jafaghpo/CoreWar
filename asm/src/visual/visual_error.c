/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:07:32 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/29 16:41:09 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		visual_error(int *option)
{
	dprintf(2, ERROR_VISUAL);
	dprintf(2, "\n");
	*g_option &= ~(VISUAL_FLAG);
}
