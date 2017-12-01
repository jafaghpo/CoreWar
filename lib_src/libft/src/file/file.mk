# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    file.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iburel <iburel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 16:21:02 by iburel            #+#    #+#              #
#    Updated: 2017/12/01 17:35:50 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCL_FILE		=	$(INCL_PATH)/file.h

SRCS_FILE		= 	ft_filetostr.c get_next_line.c
SRC_FILE		=	$(addprefix $(SRC_FILE_PATH)/, $(SRCS_FILE))
OBJS_FILE		= 	$(SRCS_FILE:.c=.o)


$(OBJ_PATH)/%.o: $(SRC_FILE_PATH)/%.c $(INCL_FILE)
	$(CC) -o $@ -c $< -I $(INCL_PATH) $(CFLAGS)