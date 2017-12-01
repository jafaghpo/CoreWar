# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_printf.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iburel <iburel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 16:26:14 by iburel            #+#    #+#              #
#    Updated: 2017/12/01 17:36:00 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCL_PRINTF		=	$(INCL_PATH)/ft_printf.h

SRCS_PRINTF		=	ft_printf.c	ft_buf.c ft_color.c ft_flags.c ft_per.c ft_pars.c \
					ft_conv.c ft_convspe.c ft_getutype.c ft_getutype2.c ft_getstype.c \
					ft_getstype2.c ft_printf_s.c ft_printf_ls.c ft_printf_c.c \
					ft_printf_putchar_fd.c ft_printf_o.c ft_printf_u.c ft_printf_x.c \
					ft_printf_b.c ft_printf_k.c ft_printf_ktoa.c ft_printf_getdaymonth.c \
					ft_printf_itoa.c ft_printf_itoa_base.c ft_printf_d.c ft_printf_strnew.c \
					ft_printf_e.c ft_printf_dtoa_e.c ft_printf_f.c ft_printf_dtoa_f.c \
					ft_printf_dtoa_ent.c ft_printf_g.c ft_printf_g_e.c ft_printf_dtoa_g_e.c \
					ft_printf_g_f.c ft_printf_dtoa_g_f.c ft_printf_a.c ft_printf_dtoa_a.c \
					ft_printf_itoa_a.c ft_printf_le.c ft_printf_dtoa_le.c ft_printf_lf.c \
					ft_printf_dtoa_lf.c ft_printf_dtoa_lent.c ft_printf_lg.c \
					ft_printf_lg_le.c ft_printf_dtoa_lg_le.c ft_printf_lg_lf.c \
					ft_printf_dtoa_lg_lf.c ft_printf_la.c ft_printf_dtoa_la.c \
					ft_printf_p.c ft_printf_ind.c
SRC_PRINTF		=	$(addprefix $(SRC_PRINTF_PATH)/, $(SRCS_PRINTF))
OBJS_PRINTF		=	$(SRCS_PRINTF:.c=.o)


$(OBJ_PATH)/%.o: $(SRC_PRINTF_PATH)/%.c $(INCL_PRINTF)
	$(CC) -o $@ -c $< -I $(INCL_PATH) $(CFLAGS)