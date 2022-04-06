# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 19:07:15 by skasmi            #+#    #+#              #
#    Updated: 2022/04/03 18:28:24 by skasmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

CLIENT = client
SERVER = server

SRCS_C = client.c \
			server_utils.c \
		
SRCS_S = server.c \
			server_utils.c \

OBJS_C = $(SRCS_C:%.c=%.o)

OBJS_S = $(SRCS_S:%.c=%.o)
	
all: $(SERVER) $(CLIENT)
	
$(CLIENT) : $(OBJS_C)
	CC -o $@ $^ $(CFLAGS)
	
$(SERVER) : $(OBJS_S)
	CC -o $@ $^ $(CFLAGS)
	
clean:
	rm -f $(OBJS_C) $(OBJS_S)

fclean:
	rm -f $(CLIENT) $(SERVER)
	
re:
	fclean all