/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:26:41 by iburel            #+#    #+#             */
/*   Updated: 2018/02/03 14:51:03 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    free_files(t_pfile *files)
{
    t_pfile     *tmp;

    while (files)
    {
        tmp = files->next;
        free(files->binary);
        free(files);
        files = tmp;
    }
}