/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:59:34 by athonda           #+#    #+#             */
/*   Updated: 2024/09/11 08:46:21 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_box *p)
{
	int		x;
	int		y;
	int		offset;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			if (p->div[x][y])
				continue ;
			p->cx = (x - p->orig_x) * (p->scale_factor * 4.0 / WIDTH);
			p->cy = (y - p->orig_y) * (p->scale_factor * 4.0 / WIDTH);
			p->x = x;
			p->y = y;
			if (fractal(p) < (p->iter + ITER_UNIT) / 2)
			{
				p->div[x][y] = 1;
				offset = y * p->line_size + (x * p->bits_per_pixel / 8);
				*(int *)(p->addr + offset) = 0x00000000;
			}
			else if (fractal(p) < (p->iter + ITER_UNIT) * 2 / 3)
			{
				p->div[x][y] = 1;
				offset = y * p->line_size + (x * p->bits_per_pixel / 8);
				*(int *)(p->addr + offset) = 0x00808080;
			}
			else if (fractal(p) < (p->iter + ITER_UNIT) * 5 / 6)
			{
				p->div[x][y] = 1;
				offset = y * p->line_size + (x * p->bits_per_pixel / 8);
				*(int *)(p->addr + offset) = 0x00c0c0c0;
			}
			else if (fractal(p) < p->iter + ITER_UNIT)
			{
				p->div[x][y] = 1;
				offset = y * p->line_size + (x * p->bits_per_pixel / 8);
				*(int *)(p->addr + offset) = 0x00f5f5f5;
			}
			else
			{
				offset = y * p->line_size + (x * p->bits_per_pixel / 8);
				*(int *)(p->addr + offset) = (128 << 24) | 0x00ff0000;
			}
		}
	}
	p->iter = p->iter + ITER_UNIT;
}
