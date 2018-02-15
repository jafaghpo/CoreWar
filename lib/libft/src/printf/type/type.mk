# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    type.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 21:18:29 by iburel            #+#    #+#              #
#    Updated: 2017/12/17 22:44:23 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_TYPEPRINTF	=	pf_int.c pf_intmax.c pf_ssize.c pf_short.c pf_long.c pf_2short.c pf_2long.c \
					pf_uint.c pf_uintmax.c pf_size.c pf_ushort.c pf_ulong.c pf_u2short.c pf_u2long.c
SRC_TYPEPRINTF	=	$(addprefix type/, $(SRCS_TYPEPRINTF))


$(OBJ_PATH)/%.o: $(SRC_TYPEPRINTF_PATH)/%.c $(INCL_PRINTF)
	$(CC) -o $@ -c $< -I $(INCL_PATH) $(CFLAGS)
