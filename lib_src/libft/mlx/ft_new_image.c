/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:34:15 by iburel            #+#    #+#             */
/*   Updated: 2017/06/28 15:44:13 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_image		ft_new_image(void *mlx, int x, int y)
{
	t_image		ret;

	ret.image = mlx_new_image(mlx, x, y);
	ret.data = (t_uint *)mlx_get_data_addr(ret.image, &ret.bpp,
											&ret.w, &ret.endian);
	ret.w >>= 2;
	ret.h = y;
	return (ret);
}
