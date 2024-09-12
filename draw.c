/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:59:34 by athonda           #+#    #+#             */
/*   Updated: 2024/09/12 16:10:13 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color(t_box *p, int n)
{
	int	rgb;
	int	color_nb;
	double	k;

	k = 0.1;
	color_nb = (int)(255 * (1 - exp(-k * n * log(1 + p->scale_factor) / log(0.7))));
	rgb = (color_nb << 16) + (color_nb << 8) + (color_nb);
	return (rgb);
}

void	draw(t_box *p)
{
	int		x;
	int		y;
	int		offset;
	int		n;

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
			n = fractal(p);
			if (n < p->iter + ITER_UNIT)
			{
				p->div[x][y] = 1;
				offset = y * p->line_size + (x * p->bits_per_pixel / 8);
				*(int *)(p->addr + offset) = color(p, n);
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
