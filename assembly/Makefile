# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/06 20:51:34 by jafaghpo          #+#    #+#              #
#    Updated: 2018/03/12 14:51:50 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	asm
CC					=	gcc
CFLAGS				=	-Werror -Wextra -Wextra
NCURSE				=	-lncurses
DEBUG				=	no

ifeq ($(DEBUG), yes)
	CFLAGS			+=	-g -D DEBUG -fsanitize=address
else
	CFLAGS			+=	-Ofast
endif

OBJ_PATH			=	obj
SRC_PATH			=	src
LIB_PATH			=	../lib

SRCS				=	main.c
SRC					=	$(addprefix $(SRC_PATH)/, $(SRCS))
OBJ					=	$(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))


SRC_GEN_PATH		=	$(SRC_PATH)/general
SRC_PARSE_PATH		=	$(SRC_PATH)/parsing
SRC_LABEL_PATH		=	$(SRC_PATH)/label
SRC_EVAL_PATH		=	$(SRC_PATH)/eval_expr
SRC_VISUAL_PATH		=	$(SRC_PATH)/visual

INCL_PATH			=	include
OP_INC_PATH			=	../include
INCL				=	$(INCL_PATH)/asm.h $(OP_INC_PATH)/op.h $(INCL_PATH)/eval_expr.h \
						$(INCL_PATH)/visual.h

include $(SRC_GEN_PATH)/general.mk
include $(SRC_PARSE_PATH)/parse.mk
include $(SRC_LABEL_PATH)/label.mk
include $(SRC_EVAL_PATH)/eval_expr.mk
include $(SRC_VISUAL_PATH)/visual.mk

LIBFT_PATH			=	$(LIB_PATH)/libft
LIBFT				=	$(LIBFT_PATH)/libft.a
LIBFT_INCL_PATH		=	$(LIBFT_PATH)/include


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIBFT) $(CFLAGS) $(NCURSE)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCL)
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCL_PATH) -I $(OP_INC_PATH) -I $(LIBFT_INCL_PATH)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
