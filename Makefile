# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 17:14:24 by lulm              #+#    #+#              #
#    Updated: 2024/06/11 05:48:12 by lionelulm        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC		= cc

CFLAGS	= -Wextra -Wall -Werror -O3

ifeq ($(shell uname), Linux)
	LIBMLX			= ./libmlx/linux
	LIBMLX_INC		= ./libmlx/linux
	LIBMLX_FLAGS	= -lmlx -lXext -lX11 -lm -lz
else
	LIBMLX   = ./libmlx/macos
	LIBMLX_INC   = ./libmlx/macos
	LIBMLX_FLAGS = -lmlx -framework openGL -framework AppKit
endif

HEADERS	= -I ./include -I $(LIBMLX)/include

LIBS 	= -Iinclude -ldl -lglfw -pthread -lm

RM		= rm -f

SRCS	=	srcs/errors.c			\
			srcs/main.c				\
			srcs/map.c				\
			srcs/moves.c			\
			srcs/game.c				\
			srcs/exit.c				\
			srcs/initialize_game.c	\
			srcs/initialize_map.c	\
			srcs/initialize_utils.c

OBJS	= $(SRCS:.c=.o)

LIBFT	= utils/libft/libft.a

PRINTF	= utils/ft_printf/libftprintf.a

MLX		= libmlx/libmlx.a

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) all -C ./utils/ft_printf
	@$(MAKE) all -C ./utils/libft
	@$(MAKE) all -C $(LIBMLX)
	@cc $(CFLAGS) $(LIBS) $(OBJS) $(LIBFT) $(PRINTF) $(LIBMLX) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) fclean -C ./utils/libft
	$(MAKE) fclean -C ./utils/ft_printf
	$(MAKE) clean -C $(LIBMLX)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./utils/libft
	$(MAKE) fclean -C ./utils/ft_printf
	$(MAKE) clean -C $(LIBMLX)

re: fclean all

.PHONY: all clean fclean re
