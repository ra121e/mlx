/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:52:34 by athonda           #+#    #+#             */
/*   Updated: 2024/09/08 08:35:34 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_box *f)
{
	int		n;
	double	tmp_r;
	double	tmp_i;
	double	zr;
	double	zi;

	zr = f->zr[f->x][f->y];
	zi = f->zi[f->x][f->y];
	n = f->iter;
	while ((zr * zr + zi * zi) < 4 && n < f->iter + ITER_UNIT)
	{
		tmp_r = zr * zr - zi * zi + f->cx;
		tmp_i = 2 * zr * zi + f->cy;
		zr = tmp_r;
		zi = tmp_i;
		n++;
	}
	f->zr[f->x][f->y] = zr;
	f->zi[f->x][f->y] = zi;
	return (n);
}
