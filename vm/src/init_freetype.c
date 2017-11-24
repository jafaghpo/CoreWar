/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_freetype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:07:38 by iburel            #+#    #+#             */
/*   Updated: 2017/11/17 14:07:39 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int     init_freetype(void)
{
    FT_Library  library;

    if (FT_Init_FreeType(&library))
    {
        ft_printf(ERROR_INIT_FREETYPE"\n");
        return (0);
    }
    return (1);
}