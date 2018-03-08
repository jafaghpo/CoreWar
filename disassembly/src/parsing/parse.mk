# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    parse.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 22:39:09 by jafaghpo          #+#    #+#              #
#    Updated: 2018/03/08 17:27:40 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PARSE			=	get_binary.c parse_binary.c get_name.c get_comment.c \
						get_instruction.c get_argument.c

SRC_PARSE			=	$(addprefix $(SRC_PARSE_PATH)/, $(SRCS_PARSE))

OBJ					+=	$(addprefix $(OBJ_PATH)/, $(SRCS_PARSE:.c=.o))

$(OBJ_PATH)/%.o: $(SRC_PARSE_PATH)/%.c $(INCL)
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCL_PATH) -I $(OP_INC_PATH) -I $(LIBFT_INCL_PATH)
