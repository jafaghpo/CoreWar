/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_chat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 02:28:24 by iburel            #+#    #+#             */
/*   Updated: 2017/11/27 02:28:26 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void    put_chat(void)
{
    int     i;

    i = 0;
    while (i < 10)
    {
        put_text(g_chat[i], 0.5f, -0.9f + (float)i * 0.08f);
        i++;
    }
}