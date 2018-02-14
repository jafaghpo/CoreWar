/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:00:32 by iburel            #+#    #+#             */
/*   Updated: 2018/02/14 14:39:53 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	init_numbers_vertices(float *vertices)
{
	vertices[0] = 0.9f;
	vertices[1] = 0.9f;
	vertices[2] = 0.9f + 16.f / (float)WIN_X * 3.f * 2.f;
	vertices[3] = 0.9f;
	vertices[4] = 0.9f;
	vertices[5] = 0.9f + 17.f / (float)WIN_Y * 2.f;
	vertices[6] = 0.9f + 16.f / (float)WIN_X * 3.f * 2.f;
	vertices[7] = 0.9f + 17.f / (float)WIN_Y * 2.f;
	vertices[8] = 0.5f;
	vertices[9] = 0.7f;
	vertices[10] = 0.5f + 16.f / (float)WIN_X * 7.f * 2.f;
	vertices[11] = 0.7f;
	vertices[12] = 0.5f;
	vertices[13] = 0.7f + 17.f / (float)WIN_Y * 2.f;
	vertices[14] = 0.5f + 16.f / (float)WIN_X * 7.f * 2.f;
	vertices[15] = 0.7f + 17.f / (float)WIN_Y * 2.f;
	vertices[16] = 0.8f;
	vertices[17] = 0.7f;
	vertices[18] = 0.8f + 16.f / (float)WIN_X * 5.f * 2.f;
	vertices[19] = 0.7f;
	vertices[20] = 0.8f;
	vertices[21] = 0.7f + 17.f / (float)WIN_Y * 2.f;
	vertices[22] = 0.8f + 16.f / (float)WIN_X * 5.f * 2.f;
	vertices[23] = 0.7f + 17.f / (float)WIN_Y * 2.f;
}

void	init_numbers_coord_text(float *coord_text)
{
	coord_text[0] = 0.f;
	coord_text[1] = 1.f;
	coord_text[2] = 1.f;
	coord_text[3] = 1.f;
	coord_text[4] = 0.f;
	coord_text[5] = 0.f;
	coord_text[6] = 1.f;
	coord_text[7] = 0.f;
	coord_text[8] = 0.f;
	coord_text[9] = 1.f;
	coord_text[10] = 1.f;
	coord_text[11] = 1.f;
	coord_text[12] = 0.f;
	coord_text[13] = 0.f;
	coord_text[14] = 1.f;
	coord_text[15] = 0.f;
	coord_text[16] = 0.f;
	coord_text[17] = 1.f;
	coord_text[18] = 1.f;
	coord_text[19] = 1.f;
	coord_text[20] = 0.f;
	coord_text[21] = 0.f;
	coord_text[22] = 1.f;
	coord_text[23] = 0.f;
}
