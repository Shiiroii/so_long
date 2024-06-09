# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 17:14:24 by lulm              #+#    #+#              #
#    Updated: 2024/06/09 09:12:20 by lionelulm        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

LIBMLX	= ./MLX

CC		= cc

CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -0fast

MLFLAG	= -I ./include -I $(LIBMLX)/include

LIBS 	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

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

OBJS	= ${SRCS:.c=.o}

LIBFT	= utils/libft/libft.a

PRINTF	= utils/ft_printf/libftprintf.a

MLX		= MLX/libmlx.a

all: liblmx ${NAME}

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(MLFLAG) $(OBJS) $(LIBFT) $(PRINTF) $(MLX) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./utils/libft fclean
	$(MAKE) -C ./utils/ft_printf fclean
	$(MAKE) -C $(LIBMLX) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./utils/libft fclean
	$(MAKE) -C ./utils/ft_printf fclean
	$(MAKE) -C $(LIBMLX) clean

re: fclean all

.PHONY: all clean fclean re
