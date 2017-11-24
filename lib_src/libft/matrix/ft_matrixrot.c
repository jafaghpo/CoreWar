/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:56:33 by iburel            #+#    #+#             */
/*   Updated: 2017/04/09 16:14:07 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix	ft_matrixrot(t_matrix *mat, t_vec *u, float tetra)
{
	t_matrix	ret;
	t_matrix	rot;

	rot = ft_matrixforrot(u, tetra);
	ret = ft_matrixmult(&rot, mat);
	ft_matrix_free(&rot);
	ft_matrix_free(mat);
	return (ret);
}
