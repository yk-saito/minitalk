# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 00:24:18 by ysaito            #+#    #+#              #
#    Updated: 2021/11/11 14:13:19 by ysaito           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Client
CNAME		= client
CSRC_DIR	= .
CSRC_FILE	= client.c
CSRC_FILE 	+= minitalk_utils.c
CSRCS		= $(addprefix $(CSRC_DIR)/,$(CSRC_FILE))
COBJS		= $(CSRCS:.c=.o)

# Server
SNAME		= server
SSRC_DIR	= .
SSRC_FILE	= server.c
SSRC_FILE 	+= minitalk_utils.c
SSRCS		= $(addprefix $(SSRC_DIR)/,$(SSRC_FILE))
SOBJS		= $(SSRCS:.c=.o)

# Client Bonus
CBONUS_SRC_DIR	= .
CBONUS_SRC_FILE	= client_bonus.c
CBONUS_SRC_FILE	+= minitalk_utils_bonus.c
CBONUS_SRCS		= $(addprefix $(CBONUS_SRC_DIR)/,$(CBONUS_SRC_FILE))
CBONUS_OBJS		= $(CBONUS_SRCS:.c=.o)

# Server Bonus
SBONUS_SRC_DIR	= .
SBONUS_SRC_FILE	= server_bonus.c
SBONUS_SRC_FILE	+= minitalk_utils_bonus.c
SBONUS_SRCS		= $(addprefix $(SBONUS_SRC_DIR)/,$(SBONUS_SRC_FILE))
SBONUS_OBJS		= $(SBONUS_SRCS:.c=.o)

# Libft
LIBS_NAME	= libft.a
LIBS_DIR	= ./libft

NAME		:= $(CNAME) $(SNAME)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

ifdef WITH_BONUS
	COBJS_SOURCE	= $(CBONUS_OBJS)
	SOBJS_SOURCE	= $(SBONUS_OBJS)
else
	COBJS_SOURCE	= $(COBJS)
	SOBJS_SOURCE	= $(SOBJS)
endif

$(CNAME):	$(COBJS_SOURCE)
$(SNAME):	$(SOBJS_SOURCE)
$(NAME):	$(COBJS_SOURCE) $(SOBJS_SOURCE)
			$(MAKE) -C $(LIBS_DIR)
			$(CC) $(CFLAGS) -o $(CNAME) $(COBJS_SOURCE) -L $(LIBS_DIR) -lft
			$(CC) $(CFLAGS) -o $(SNAME) $(SOBJS_SOURCE) -L $(LIBS_DIR) -lft

all:		$(NAME)

clean:
			$(MAKE) -C $(LIBS_DIR) clean
			$(RM) $(COBJS) $(CBONUS_OBJS)
			$(RM) $(SOBJS) $(SBONUS_OBJS)

fclean:		clean
			$(MAKE) -C $(LIBS_DIR) fclean
			$(RM) $(CNAME)
			$(RM) $(SNAME)

re:			fclean all

bonus:
			make WITH_BONUS=1 all


.PHONY:		all clean fclean re bonus
