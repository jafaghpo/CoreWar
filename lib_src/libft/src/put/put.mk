# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    put.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iburel <iburel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 16:27:01 by iburel            #+#    #+#              #
#    Updated: 2017/12/01 17:37:39 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCL_PUT		=	$(INCL_PATH)/put.h

SRCS_PUT		=	ft_afferror.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
					ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putnbrendl.c \
					ft_putstr.c ft_putstr_fd.c
SRC_PUT			=	$(addprefix $(SRC_PUT_PATH)/, $(SRCS_PUT))
OBJS_PUT		=	$(SRCS_PUT:.c=.o)


$(OBJ_PATH)/%.o: $(SRC_PUT_PATH)/%.c $(INCL_PUT)
	$(CC) -o $@ -c $< -I $(INCL_PATH) $(CFLAGS)