/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 00:32:27 by iburel            #+#    #+#             */
/*   Updated: 2017/09/04 20:42:37 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"
#include <stdlib.h>

void	translation(t_mat4 *m, t_vec3 u)
{
	t_mat4	trans;
	t_mat4	tmp;

	trans = mat4_unit();
	trans[12] = u.x;
	trans[13] = u.y;
	trans[14] = u.z;
	tmp = *m;
	*m = mat4_mult(trans, *m);
	free(tmp);
	free(trans);
}
