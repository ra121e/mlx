/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:06:47 by athonda           #+#    #+#             */
/*   Updated: 2024/09/04 21:08:53 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800

# include <stdio.h>
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
	double	scale_factor;
};

void	draw(char *addr, int bits_per_pixel, int line_size, double scale_factor);
int	mouse_zoom(int button,int x,int y, t_box *p);
int	mandelbrot(double cx, double cy);
#endif //FRACTOL_H