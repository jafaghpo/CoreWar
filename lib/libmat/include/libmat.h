/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 22:12:22 by iburel            #+#    #+#             */
/*   Updated: 2018/02/16 16:34:46 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMAT_H
# define LIBMAT_H

# include <math.h>

# define RADIANS(x) (x / 360.0 * 2.0 * M_PI)

typedef float*			t_mat4;
typedef struct s_vec2	t_vec2;
typedef struct s_vec3	t_vec3;
typedef struct s_vec4	t_vec4;
typedef struct s_ivec2	t_ivec2;
typedef struct s_ivec3	t_ivec3;
typedef struct s_ivec4	t_ivec4;

struct	s_vec2
{
	float x;
	float y;
};

struct	s_vec3
{
	float x;
	float y;
	float z;
};

struct	s_vec4
{
	float x;
	float y;
	float z;
	float w;
};

struct	s_ivec2
{
	int	x;
	int	y;
};

struct	s_ivec3
{
	int	x;
	int	y;
	int	z;
};

struct	s_ivec4
{
	int	x;
	int	y;
	int	z;
	int	w;
};

t_mat4	mat4_new(void);
t_mat4	mat4_empty(void);
t_mat4	mat4_copy(t_mat4 src);
t_mat4	mat4_unit(void);
t_mat4	mat4_mult(t_mat4 m1, t_mat4 m2);
t_vec4	mat4_vec4_mult(t_mat4 m, t_vec4 u);

t_vec3	norme(float x, float y, float z);

t_mat4	perspective(float angle, float ratio, float near, float far);
void	rotate(t_mat4 *m, t_vec3 u, float teta);
void	translation(t_mat4 *m, t_vec3 u);
t_mat4	setlimits(t_vec3 u, t_vec3 v);
void	zoom(t_mat4 *m, t_vec3 u);

void	mat4_put(t_mat4 m);
void	vec4_put(t_vec4 m);

#endif
