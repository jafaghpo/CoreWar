/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:45:55 by iburel            #+#    #+#             */
/*   Updated: 2017/06/28 22:26:14 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTMLX_H
# define FTMLX_H

# include <mlx.h>

typedef struct s_image		t_image;
typedef struct s_line		t_line;
typedef struct s_cart		t_cart;
typedef struct s_point2d	t_point2d;

struct	s_point2d
{
	int		x;
	int		y;
};

struct	s_cart
{
	int		a;
	int		b;
	int		c;
};

struct	s_line
{
	t_point2d	a;
	t_point2d	b;
};

struct	s_image
{
	void	*image;
	t_uint	*data;
	int		bpp;
	int		w;
	int		h;
	int		endian;
};

t_image	ft_new_image(void *mlx, int x, int y);
void	ft_putpixel(t_image *image, int x, int y, t_uint color);
void	ft_putpixel_secure(t_image *image, int x, int y, t_uint color);
void	ft_clear_image(t_image *img, t_uint color);
int		ft_change_points(t_image *img, t_line *l);
void	ft_line(t_image *img, t_line l, t_uint color);
void	ft_line_secure(t_image *img, t_line l, t_uint color);
void	ft_line_vertical(t_image *img, t_point2d a, int size, t_uint color);
void	ft_line_vertical_secure(t_image *img, t_point2d a, int s, t_uint color);
void	ft_line_horizontal(t_image *img, t_point2d a, int s, t_uint color);
void	ft_line_horizontal_secure(t_image *img, t_point2d a, int s, t_uint col);

#endif
