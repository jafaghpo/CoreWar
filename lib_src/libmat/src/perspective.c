/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 22:35:03 by iburel            #+#    #+#             */
/*   Updated: 2018/02/14 18:06:53 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"
#include "math.h"

t_mat4	perspective(float angle, float ratio, float near, float far)
{
	t_mat4	ret;
	float	xmax;
	float	ymax;
	float	tmp[4];

	ymax = near * tanf(angle);
	xmax = ymax * ratio;
	tmp[0] = 2.f * near;
	tmp[1] = xmax + xmax;
	tmp[2] = ymax + ymax;
	tmp[3] = far - near;
	ret = mat4_empty();
	ret[0] = tmp[0] / tmp[1];
	ret[5] = tmp[0] / tmp[2];
	ret[10] = (-far - near) / tmp[3];
	ret[11] = -1.0;
	ret[14] = (-tmp[0] * far) / tmp[3];
	return (ret);
}
