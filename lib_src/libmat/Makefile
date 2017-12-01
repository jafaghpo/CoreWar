# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iburel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/26 16:25:27 by iburel            #+#    #+#              #
#    Updated: 2017/12/01 18:56:05 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libmat.a
CC				=	gcc

ifeq ($(DEBUG), yes)
	CFLAGS		=	 -g
else
	CFLAGS		=	 -Wall -Werror -Wextra -Ofast
endif

SRCS			=	mat4_mult.c mat4_unit.c mat4_put.c mat4_empty.c perspective.c \
					mat4_new.c rotate.c translation.c mat4_vec4_mult.c vec4_put.c \
					norme.c mat4_copy.c setlimits.c zoom.c
SRC				=	$(addprefix src/, $(SRCS))
OBJ				=	$(addprefix obj/, $(SRCS:.c=.o))

INCL_PATH		=	include
INCL			=	$(INCL_PATH)/libmat.h

all: $(NAME) $(NAME_AFF)

$(NAME):$(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

obj/%.o: src/%.c $(INCL)
	$(CC) -c -o $@ $< $(CFLAGS) -I $(INCL_PATH)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
