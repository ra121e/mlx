# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 19:45:09 by athonda           #+#    #+#              #
#    Updated: 2024/09/04 16:41:21 by athonda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

SRCS	=	main.c mandelbrot.c event.c

OBJS	=	$(patsubst %.c,%.o,$(SRCS))

CFLAGS	=	-Wall -Wextra -Werror

XFLAGS	=	-lXext -lX11 -lm

IFLAGS	=	-I./minilibx-linux

LIBFT_DIR	=	./libft
LIBFT	=	$(LIBFT_DIR)/libft.a

LIBMLX_DIR	=	./minilibx-linux
LIBMLX	=	$(LIBMLX_DIR)/libmlx.a

all:	$(NAME)

$(NAME): $(OBJS)
	cc $(OBJS) $(LIBMLX) $(CFLAGS) $(XFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

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