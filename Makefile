# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 16:13:58 by zchtaibi          #+#    #+#              #
#    Updated: 2024/04/28 17:22:31 by zchtaibi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CNAME = client
SNAME = server

CBONUS_NAME = client_bonus
SBONUS_NAME = server_bonus

CSRC = client.c
SSRC = server.c

COBJS = $(CSRC:.c=.o)
SOBJS = $(SSRC:.c=.o)

CBONUS_SRC = client_bonus.c
SBONUS_SRC = server_bonus.c

SBONUS_OBJS = $(SBONUS_SRC:.c=.o)
CBONUS_OBJS = $(CBONUS_SRC:.c=.o)

UTILSRC = utils.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(CNAME) $(SNAME) 

bonus: $(CBONUS_NAME) $(SBONUS_NAME)

$(SNAME): $(SOBJS) $(UTILSRC)
	$(CC) $(CFLAGS) $(UTILSRC) $(SOBJS) -o $(SNAME)

$(CNAME): $(COBJS) $(UTILSRC)
	$(CC) $(CFLAGS) $(UTILSRC) $(COBJS) -o $(CNAME)

$(SBONUS_NAME): $(SBONUS_OBJS) $(UTILSRC)
	$(CC) $(CFLAGS) $(UTILSRC) $(SBONUS_OBJS) -o $(SBONUS_NAME)

$(CBONUS_NAME): $(CBONUS_OBJS) $(UTILSRC)
	$(CC) $(CFLAGS) $(UTILSRC) $(CBONUS_OBJS) -o $(CBONUS_NAME)
	
clean:
	$(RM) $(COBJS) $(SOBJS) $(CBONUS_OBJS) $(SBONUS_OBJS)

fclean: clean
	$(RM) $(CNAME) $(SNAME) $(CBONUS_NAME) $(SBONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re 