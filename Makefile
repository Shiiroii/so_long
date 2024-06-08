# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 17:14:24 by lulm              #+#    #+#              #
#    Updated: 2024/06/08 11:04:27 by lionelulm        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

HEADER	= so_long.h

CC		= cc

CFLAGS	= -Wextra -Wall -Werror

MLFLAG	= -lmlx_Linux -lft -lmlx -lm -lXext -lX11

RM		= rm -f

SRCS	=	errors.c			\
			main.c				\
			map.c				\
			moves.c				\
			game.c				\
			exit.c				\
			initialize_game.c	\
			initialize_map.c	\
			initialize_utils.c

LIBMLX	= ../MLX42

OBJS	= ${SRCS:.c=.o}

LIBFT	= utils/libft/libft.a

PRINTF	= utils/ft_printf/libftprintf.a

MLX		= MLX/libmlx.a

all:	${NAME}

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(MLX)
		$(CC) $(CFLAGS) $(MLFLAG) $(OBJS) $(LIBFT) $(PRINTF) $(MLX) -o $(NAME)

clean:
		rm -f $(OBJS)
		$(MAKE) -C ./libft fclean
		$(MAKE) -C ./ft_printf fclean
		$(MAKE)	-C $(LIBMLX) clean

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C ./libft fclean
		$(MAKE) -C ./ft_printf fclean
		$(MAKE)	-C $(LIBMLX) clean

re:		fclean all

.PHONY: all clean fclean re
