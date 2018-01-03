# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    visual.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 22:48:22 by jafaghpo          #+#    #+#              #
#    Updated: 2018/01/03 22:49:50 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_VISUAL_PATH		=	src/visual

SRCS_VISUAL			=	run_visual.c

SRC_VISUAL			=	$(addprefix $(SRC_VISUAL_PATH)/, $(SRCS_VISUAL))

OBJ					+=	$(addprefix $(OBJ_PATH)/, $(SRCS_VISUAL:.c=.o))

$(OBJ_PATH)/%.o: $(SRC_VISUAL_PATH)/%.c $(INCL)
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCL_PATH) -I $(OP_INC_PATH) -I $(LIBFT_INCL_PATH)
