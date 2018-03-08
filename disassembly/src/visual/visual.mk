# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    visual.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 22:48:22 by jafaghpo          #+#    #+#              #
#    Updated: 2018/03/08 17:27:48 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_VISUAL			=	setup_visual.c run_visual.c clear_tab.c reset_visual.c \
						wait_event.c wait_end.c delete_visual.c store_line.c

SRC_VISUAL			=	$(addprefix $(SRC_VISUAL_PATH)/, $(SRCS_VISUAL))

OBJ					+=	$(addprefix $(OBJ_PATH)/, $(SRCS_VISUAL:.c=.o))

$(OBJ_PATH)/%.o: $(SRC_VISUAL_PATH)/%.c $(INCL)
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCL_PATH) -I $(OP_INC_PATH) -I $(LIBFT_INCL_PATH)
