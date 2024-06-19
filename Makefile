# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 17:14:24 by lulm              #+#    #+#              #
#    Updated: 2024/06/19 16:02:54 by lulm             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC		= cc

CFLAGS	= -Wextra -Wall -Werror -g -fsanitize=address

LFLAGS 	= -Iinclude -ldl -lglfw -pthread -lm -lmlx -lmlx_Linux -lX11 -lXext

RM		= rm -f

SRCS	=	srcs/errors.c			\
			srcs/main.c				\
			srcs/map.c				\
			srcs/moves.c			\
			srcs/game.c				\
			srcs/exit.c				\
			srcs/initialize_game.c	\
			srcs/initialize_map.c	\
			srcs/initialize_utils.c	\
			srcs/is_it_valid.c		\
			srcs/copy_map.c			\
			srcs/floodfill.c

OBJS	= $(SRCS:.c=.o)

LIBFT	= utils/libft/libft.a

PRINTF	= utils/ft_printf/libftprintf.a

MLX		= utils/MLX

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) all -C ./utils/ft_printf
	$(MAKE) all -C ./utils/libft
	$(MAKE) all -C ./utils/MLX
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -L $(MLX) $(LFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) fclean -C ./utils/libft
	$(MAKE) fclean -C ./utils/ft_printf
	$(MAKE) clean -C ./utils/MLX

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./utils/libft
	$(MAKE) fclean -C ./utils/ft_printf
	$(MAKE) clean -C ./utils/MLX

re: fclean all

.PHONY: all clean fclean re
