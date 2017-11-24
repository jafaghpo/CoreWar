/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 20:55:42 by iburel            #+#    #+#             */
/*   Updated: 2017/09/17 01:52:24 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"
#include <math.h>
#include <stdlib.h>

static t_mat4	get_mat_rot(t_vec3 u, float teta)
{
	t_mat4	mat_rot;
	float	c;
	float	s;

	c = cos(teta);
	s = sin(teta);
	mat_rot = mat4_empty();
	mat_rot[0] = u.x * u.x * (1.0 - c) + c;
	mat_rot[1] = u.x * u.y * (1.0 - c) + u.z * s;
	mat_rot[2] = u.x * u.z * (1.0 - c) - u.y * s;
	mat_rot[4] = u.y * u.x * (1.0 - c) - u.z * s;
	mat_rot[5] = u.y * u.y * (1.0 - c) + c;
	mat_rot[6] = u.y * u.z * (1.0 - c) + u.x * s;
	mat_rot[8] = u.z * u.x * (1.0 - c) + u.y * s;
	mat_rot[9] = u.z * u.y * (1.0 - c) - u.x * s;
	mat_rot[10] = u.z * u.z * (1.0 - c) + c;
	mat_rot[15] = 1.0;
	return (mat_rot);
}

#include <stdio.h>

void			rotate(t_mat4 *m, t_vec3 u, float teta)
{
	t_mat4	mat_rot;
	t_mat4	tmp;

	mat_rot = get_mat_rot(u, teta);
	tmp = *m;
	*m = mat4_mult(mat_rot, *m);
	free(tmp);
	free(mat_rot);
}
