/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pos_players.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 23:51:17 by iburel            #+#    #+#             */
/*   Updated: 2018/01/30 16:31:25 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void get_used(t_file *files, int nb_players, char *tab)
{
    while (files)
    {
        if (files->pos != -1)
        {
            if (files->pos >= nb_players || tab[files->pos])
                ft_afferror("error pos player");
            tab[files->pos] = 1;
        }
        files = files->next;
    }
}

static void fill_pos(t_file *files, char *tab)
{
    int    i;

    i = 0;
    while (files)
    {
        if (files->pos == -1)
        {
            while (tab[i] != 0)
               i++;
            files->pos = i - 1;
            i++;
        }
        else
            files->pos--;
        files = files->next;
    }
}

void        fill_pos_players(t_file *files, int nb_players)
{
    char    tab[nb_players];

    ft_bzero(tab, nb_players);
    tab[0] = 1;
    get_used(files, nb_players, tab);
    fill_pos(files, tab);
}