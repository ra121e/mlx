/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:52:34 by athonda           #+#    #+#             */
/*   Updated: 2024/09/03 19:53:45 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double cx, double cy)
{
	int		n;
	double	tmp_r;
	double	tmp_i;
	double	zr;
	double	zi;

	zr = 0.0;
	zi = 0.0;
	n = 0;
	while (n < 100 && (zr * zr + zi * zi) < 4)
	{
		tmp_r = zr * zr - zi * zi + cx;
		tmp_i = 2 * zr * zi + cy;
		zr = tmp_r;
		zi = tmp_i;
		n++;
	}
	return (n);
}
