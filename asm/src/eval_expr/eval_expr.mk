# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    eval_expr.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/02 20:37:31 by jafaghpo          #+#    #+#              #
#    Updated: 2018/01/02 20:37:33 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_BC				=	atoi_base.c bitwise_op.c eval_stack.c eval_token.c \
						eval_expr.c lexer.c bc_op.c stack.c
SRC_BC				=	$(addprefix $(SRC_BC_PATH)/, $(SRCS_BC))

OBJ					+=	$(addprefix $(OBJ_PATH)/, $(SRCS_BC:.c=.o))

$(OBJ_PATH)/%.o: $(SRC_BC_PATH)/%.c $(INCL)
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCL_PATH) -I $(OP_INC_PATH) -I $(LIBFT_INCL_PATH)
