/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:52:34 by athonda           #+#    #+#             */
/*   Updated: 2024/09/11 18:56:45 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_box *p)
{
	int		n;
	double	tmp_r;
	double	tmp_i;
	double	zr;
	double	zi;

	zr = p->zr[p->x][p->y];
	zi = p->zi[p->x][p->y];
	n = p->iter;
	while ((zr * zr + zi * zi) < 4 && n < p->iter + ITER_UNIT)
	{
		tmp_r = zr * zr - zi * zi + p->cx;
		tmp_i = 2 * zr * zi + p->cy;
		zr = tmp_r;
		zi = tmp_i;
		n++;
	}
	p->zr[p->x][p->y] = zr;
	p->zi[p->x][p->y] = zi;
	return (n);
}
