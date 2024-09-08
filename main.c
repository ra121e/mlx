/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:47:30 by athonda           #+#    #+#             */
/*   Updated: 2024/09/08 08:25:24 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int event_handler(int key, void *mlx)
{
 (void)key;
 (void)mlx;
 printf("called\n");
 return (0);
}

void	draw(t_box *f)
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
			if (f->div[x][y])
				continue ;
			f->cx = (x - f->orig_x) * (f->scale_factor * 4.0 / WIDTH);
			f->cy = (y - f->orig_y) * (f->scale_factor * 4.0 / WIDTH);
			f->x = x;
			f->y = y;
			if (mandelbrot(f) < f->iter + ITER_UNIT)
			{
				f->div[x][y] = 1;
				offset = y * f->line_size + (x * f->bits_per_pixel / 8);
				*(int *)(f->addr + offset) = 0x00FF0000;
			}
		}
	}
	f->iter = f->iter + ITER_UNIT;
}

int main(void)
{
	t_box	*f;
	int		i;
	int		j;

	f = (t_box *)malloc(sizeof (t_box) * 1);
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, &f->line_size, &f->endian);
	f->scale_factor = 1.0;
	f->orig_x = WIDTH * 2.0 / 3.0;
	f->orig_y = HEIGHT / 2.0;
	f->iter = 0;
	f->trigger = 1;
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			f->zr[i][j] = 0.0;
			f->zi[i][j] = 0.0;
			j++;
		}
		i++;
	}
	draw(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_mouse_hook(f->win, mouse_zoom, f);
	mlx_loop_hook(f->mlx, loop_hook, f);

	mlx_hook(f->win, KeyPress, KeyPressMask, event_handler, f->mlx);
	mlx_loop(f->mlx);
}
