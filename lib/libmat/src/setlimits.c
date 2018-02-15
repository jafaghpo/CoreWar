/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setlimits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:27:24 by iburel            #+#    #+#             */
/*   Updated: 2017/11/09 20:33:49 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat4	setlimits(t_vec3 u, t_vec3 v)
{
	t_mat4	ret;
	float	tmp1;
	float	tmp2;
	float	tmp3;
	float	tmp4;

	tmp1 = 2.f * u.z;
	tmp2 = v.x - u.x;
	tmp3 = v.y - u.x;
	tmp4 = v.z - u.z;
	ret = mat4_empty();
	ret[0] = tmp1 / tmp2;
	ret[5] = tmp1 / tmp3;
	ret[8] = (u.x + v.x) / tmp2;
	ret[9] = (u.y + v.y) / tmp3;
	ret[10] = (-u.z - v.z) / tmp4;
	ret[11] = -1.f;
	ret[14] = (-tmp1 * v.z) / tmp4;
	return (ret);
}
