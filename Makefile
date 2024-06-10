# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 17:14:24 by lulm              #+#    #+#              #
#    Updated: 2024/06/10 14:24:19 by lulm             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

LIBMLX	= MLX42

CC		= cc

CFLAGS	= -Wextra -Wall -Werror -O3

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

MLX		= MLX42/libmlx.a

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) all -C ./utils/ft_printf
	@$(MAKE) all -C ./utils/libft
	@$(MAKE) all -C ./MLX42
	@cc $(CFLAGS) $(LIBS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) fclean -C ./utils/libft
	$(MAKE) fclean -C ./utils/ft_printf
	$(MAKE) clean -C ./MLX42

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./utils/libft fclean
	$(MAKE) -C ./utils/ft_printf fclean
	$(MAKE) -C ./MLX42 clean

re: fclean all

.PHONY: all clean fclean re
