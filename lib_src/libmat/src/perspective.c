/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 22:35:03 by iburel            #+#    #+#             */
/*   Updated: 2017/08/29 20:51:26 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"
#include "math.h"

t_mat4	perspective(float angle, float ratio, float near, float far)
{
	t_mat4	ret;
	float	xmax, ymax;
	float	tmp, tmp2, tmp3, tmp4;

	ymax = near * tanf(angle);
	xmax = ymax * ratio;
	tmp = 2.f * near;
	tmp2 = xmax + xmax;
	tmp3 = ymax + ymax;
	tmp4 = far - near;
	ret = mat4_empty();
	ret[0] = tmp / tmp2;
	ret[5] = tmp / tmp3;
	ret[10] = (-far - near) / tmp4;
	ret[11] = -1.0;
	ret[14] = (-tmp * far) / tmp4;
	return (ret);
}