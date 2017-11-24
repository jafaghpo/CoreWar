/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:38:30 by iburel            #+#    #+#             */
/*   Updated: 2017/11/13 17:38:32 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"
#include <stdlib.h>

void	zoom(t_mat4 *m, t_vec3 u)
{
    t_mat4	trans;
	t_mat4	tmp;

	trans = mat4_unit();
	trans[0] = u.x;
	trans[5] = u.y;
	trans[10] = u.z;
	tmp = *m;
	*m = mat4_mult(trans, *m);
	free(tmp);
	free(trans);
}