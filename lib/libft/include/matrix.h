/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:10:41 by iburel            #+#    #+#             */
/*   Updated: 2017/04/09 15:25:19 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

struct		s_matrix
{
	unsigned int	ligne;
	unsigned int	colonne;
	float			**matrix;
};

struct		s_vec
{
	float	x;
	float	y;
	float	z;
};

struct		s_point
{
	float	x;
	float	y;
	float	z;
};

t_matrix	ft_matrixforrot(t_vec *u, float teta);
t_matrix	ft_matrixmult(t_matrix *mat1, t_matrix *mat2);
void		ft_matrixaddfloat(t_matrix *mat, float x, float y, float z);
t_matrix	ft_matrixnew(unsigned int ligne, unsigned int colonne);
void		ft_matrix_free(t_matrix *matrix);
t_matrix	ft_matrixrot(t_matrix *mat, t_vec *u, float teta);
t_vec		ft_vecunit(float x, float y, float z);

#endif
