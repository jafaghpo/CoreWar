/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:51:41 by iburel            #+#    #+#             */
/*   Updated: 2017/11/09 19:54:02 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat4	mat4_copy(t_mat4 src)
{
	t_mat4	dest;
	int		i;

	dest = mat4_new();
	i = 0;
	while (i < 16)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
