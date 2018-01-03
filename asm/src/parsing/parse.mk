# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    parse.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 22:39:09 by jafaghpo          #+#    #+#              #
#    Updated: 2018/01/03 22:50:12 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PARSE_PATH		=	src/parsing

SRCS_PARSE			=	parse_file.c parse_header.c parse_core.c

SRC_PARSE			=	$(addprefix $(SRC_PARSE_PATH)/, $(SRCS_PARSE))

OBJ					+=	$(addprefix $(OBJ_PATH)/, $(SRCS_PARSE:.c=.o))

$(OBJ_PATH)/%.o: $(SRC_PARSE_PATH)/%.c $(INCL)
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCL_PATH) -I $(OP_INC_PATH) -I $(LIBFT_INCL_PATH)
