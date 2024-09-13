/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:06:47 by athonda           #+#    #+#             */
/*   Updated: 2024/09/13 13:42:10 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800
# define ITER_MAX 1000
# define ITER_UNIT 50
# define ZOOM_IN_FACTOR 0.7
# define ZOOM_OUT_FACTOR 1.3
# define JULIA_CX -0.17
# define JULIA_CY 0.66
# define K_VALUE -0.1
# include <stdio.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <math.h>
# include "mlx_int.h"
# include "mlx.h"

typedef struct s_box	t_box;
struct s_box
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_size;
	int		endian;
	char	set;
	double	jx;
	double	jy;
	double	scale_factor;
	double	orig_x;
	double	orig_y;
	int		x;
	int		y;
	double	cx;
	double	cy;
	int		iter;
	int		div[WIDTH][HEIGHT];
	double	zr[WIDTH][HEIGHT];
	double	zi[WIDTH][HEIGHT];
	int		red;
	int		green;
	int		blue;
};

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	error_arg(void);
void	error_julia(void);
void	error_fractal(void);
int		ft_isdigit(int c);
int		ft_isspace(char c);
int		ft_space_sign(char *str, int *sign);
double	ft_atof(char *str);
int		check_arg(int ac, char *av[], t_box *p);
void	set_fractal(t_box *p, char *av[]);
int		init(t_box *p);
void	init_var(t_box *p);
void	init_again(t_box *p);
void	finish(t_box *p, int exit_code);
double	fractal(t_box *p);
void	put_color(t_box *p, int n);
int		color(t_box *p, int n);
void	draw(t_box *p);
int		mouse_zoom(int button, int x, int y, t_box *p);
int		key_esc(int key, t_box *p);
int		close_window(t_box *p);
int		loop_hook(t_box *p);
int		mandelbrot(t_box *p);
int		julia(t_box *p);
int		burning_ship(t_box *p);
#endif //FRACTOL_H
