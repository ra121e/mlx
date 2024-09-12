/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:34:05 by athonda           #+#    #+#             */
/*   Updated: 2024/09/12 23:35:30 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

int	burning_ship(t_box *p)
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
		zr = fabs(zr);
		zi = fabs(zi);
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
