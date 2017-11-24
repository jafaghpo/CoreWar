/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixforrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:58:40 by iburel            #+#    #+#             */
/*   Updated: 2017/04/09 16:16:41 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix	ft_matrixforrot(t_vec *u, float teta)
{
	t_matrix	ret;
	float		c;
	float		s;

	ret = ft_matrixnew(3, 3);
	c = cos(teta);
	s = sin(teta);
	ret.matrix[0][0] = u->x * u->x * (1 - c) + c;
	ret.matrix[0][1] = u->x * u->y * (1 - c) - u->z * s;
	ret.matrix[0][2] = u->x * u->z * (1 - c) + u->y * s;
	ret.matrix[1][0] = u->x * u->y * (1 - c) + u->z * s;
	ret.matrix[1][1] = u->y * u->y * (1 - c) + c;
	ret.matrix[1][2] = u->y * u->z * (1 - c) - u->x * s;
	ret.matrix[2][0] = u->x * u->z * (1 - c) - u->y * s;
	ret.matrix[2][1] = u->y * u->z * (1 - c) + u->x * s;
	ret.matrix[2][2] = u->z * u->z * (1 - c) + c;
	return (ret);
}
