# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    label.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/06 16:08:00 by jafaghpo          #+#    #+#              #
#    Updated: 2018/02/24 17:12:25 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_LABEL			=	check_labels.c valid_label.c add_label.c add_tmp_label.c \
						delete_label.c

SRC_LABEL			=	$(addprefix $(SRC_LABEL_PATH)/, $(SRCS_LABEL))

OBJ					+=	$(addprefix $(OBJ_PATH)/, $(SRCS_LABEL:.c=.o))

$(OBJ_PATH)/%.o: $(SRC_LABEL_PATH)/%.c $(INCL)
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCL_PATH) -I $(OP_INC_PATH) -I $(LIBFT_INCL_PATH)
