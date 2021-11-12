# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 20:31:03 by ysaito            #+#    #+#              #
#    Updated: 2021/11/12 20:33:10 by ysaito           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Client
CNAME		= client
CSRC_DIR	= .
CSRC_FILE	= client.c
CSRCS		= $(addprefix $(CSRC_DIR)/,$(CSRC_FILE))
COBJS		= $(CSRCS:.c=.o)

# Server
SNAME		= server
SSRC_DIR	= .
SSRC_FILE	= server.c
SSRCS		= $(addprefix $(SSRC_DIR)/,$(SSRC_FILE))
SOBJS		= $(SSRCS:.c=.o)

NAME		:= $(CNAME) $(SNAME)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

$(CNAME):	$(COBJS)
$(SNAME):	$(SOBJS)
$(NAME):	$(COBJS) $(SOBJS)
			$(CC) $(CFLAGS) -o $(CNAME) $(COBJS)
			$(CC) $(CFLAGS) -o $(SNAME) $(SOBJS)

all:		$(NAME)

clean:
			$(RM) $(COBJS) $(CBONUS_OBJS)
			$(RM) $(SOBJS) $(SBONUS_OBJS)

fclean:		clean
			$(RM) $(CNAME)
			$(RM) $(SNAME)

re:			fclean all

.PHONY:		all clean fclean re
