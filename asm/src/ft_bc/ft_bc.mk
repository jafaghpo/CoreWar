# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_bc.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 21:19:28 by jafaghpo          #+#    #+#              #
#    Updated: 2017/12/15 21:35:16 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_BC_PATH			=	$(SRC_PATH)/ft_bc
SRCS_BC				=	atoi_base.c bitwise_op.c eval_stack.c eval_token.c \
						ft_bc.c lexer.c bc_op.c stack.c
SRC_BC				=	$(addprefix $(SRC_BC_PATH)/, $(SRCS_BC))

OBJ					+=	$(addprefix $(OBJ_PATH)/, $(SRCS_BC:.c=.o))

$(OBJ_PATH)/%.o: $(SRC_BC_PATH)/%.c $(INCL)
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCL_PATH) -I $(OP_INC_PATH) -I $(LIBFT_INCL_PATH)
