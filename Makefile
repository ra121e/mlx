# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 19:45:09 by athonda           #+#    #+#              #
#    Updated: 2024/09/11 19:47:13 by athonda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

SRCS	=	main.c error.c ft_atof.c init.c finish.c event.c draw.c \
			fractal.c mandelbrot.c julia.c \

OBJS	=	$(patsubst %.c,%.o,$(SRCS))

CFLAGS	=	-Wall -Wextra -Werror -O2 -g3

XFLAGS	=	-lXext -lX11 -lm

IFLAGS	=	-I./minilibx-linux

LIBFT_DIR	=	libft
LIBFT	=	$(LIBFT_DIR)/libft.a

LIBMLX_DIR	=	minilibx-linux
LIBMLX	=	$(LIBMLX_DIR)/libmlx.a

MLX_URL	= https://github.com/42Paris/minilibx-linux.git

all:	$(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	cc $(CFLAGS) $(OBJS) $(LIBMLX) $(LIBFT) $(XFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBMLX):
	rm -rf $(LIBMLX_DIR)
	git clone $(MLX_URL)
	$(MAKE) -C $(LIBMLX_DIR)

%.o: %.c fractol.h
	cc $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re