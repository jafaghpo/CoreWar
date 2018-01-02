/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:40:11 by iburel            #+#    #+#             */
/*   Updated: 2017/12/03 17:53:58 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

typedef char				t_int8;
typedef short int			t_int16;
typedef int					t_int32;
typedef long int			t_int64;
typedef unsigned char		t_uint8;
typedef unsigned short int	t_uint16;
typedef unsigned int		t_uint32;
typedef unsigned long int	t_uint64;

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <wchar.h>
# include <limits.h>
# include <inttypes.h>
# include <math.h>
# include <stdio.h>
# include <stdarg.h>
# include "typedef.h"
# include "char.h"
# include "conv.h"
# include "cplx.h"
# include "file.h"
# include "lst.h"
# include "mem.h"
# include "put.h"
# include "str.h"
# include "ft_printf.h"

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

#endif
