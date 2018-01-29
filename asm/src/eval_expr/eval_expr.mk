# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    eval_expr.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/02 20:37:31 by jafaghpo          #+#    #+#              #
#    Updated: 2018/01/27 15:40:34 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_EVAL			=	atoi_base.c bitwise_op.c eval_stack.c eval_token.c \
						eval_expr.c lexer.c reg_op.c stack.c

SRC_EVAL			=	$(addprefix $(SRC_EVAL_PATH)/, $(SRCS_EVAL))

OBJ					+=	$(addprefix $(OBJ_PATH)/, $(SRCS_EVAL:.c=.o))

$(OBJ_PATH)/%.o: $(SRC_EVAL_PATH)/%.c $(INCL)
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCL_PATH) -I $(OP_INC_PATH) -I $(LIBFT_INCL_PATH)
