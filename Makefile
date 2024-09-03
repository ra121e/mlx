# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 19:45:09 by athonda           #+#    #+#              #
#    Updated: 2024/09/03 21:06:19 by athonda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

SRCS	=	main.c mandelbrot.c

OBJS	=	$(patsubst %.c,%.o,$(SRCS))

CFLAGS	=	-Wall -Wextra -Werror -lXext -lX11 -lm

LIBFT_DIR	=	./libft
LIBFT	=	$(LIBFT_DIR)/libft.a

MLX_DIR	=	./minilibx-linux
LIBMLX	=	$(LIBMLX_DIR)/libmlx.a

all:	$(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c fractol.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re