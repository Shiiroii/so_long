# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 17:14:24 by lulm              #+#    #+#              #
#    Updated: 2024/06/09 09:49:45 by lulm             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

LIBMLX	= MLX/libmlx42.a

CC		= cc

CFLAGS	= -Wextra -Wall -Werror -g3

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

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) all -C ./printf
	@$(MAKE) all -C ./libft
	@cp $(LIBFT) (PRINTF) $(NAME)
	@cc $(CFLAGS) $(LIBS) $(OBJS) $(LIBFT) $(PRINTF) $(LIBMLX) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) fclean -C ./utils/libft
	$(MAKE) fclean -C ./utils/ft_printf
	$(MAKE) clean -C $(LIBMLX)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./utils/libft fclean
	$(MAKE) -C ./utils/ft_printf fclean
	$(MAKE) -C $(LIBMLX) clean

re: fclean all

.PHONY: all clean fclean re
