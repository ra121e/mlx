/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:47:30 by athonda           #+#    #+#             */
/*   Updated: 2024/09/07 19:12:03 by athonda          ###   ########.fr       */
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
	double	cx;
	double	cy;
	int		offset;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			cx = (x - f->orig_x) * (f->scale_factor * 4.0 / WIDTH);
			cy = (y - f->orig_y) * (f->scale_factor * 4.0 / WIDTH);
			if (mandelbrot(cx, cy) == ITER_MAX)
			{
				offset = y * f->line_size + (x * f->bits_per_pixel / 8);
				*(int *)(f->addr + offset) = 0x00FF0000;
			}
			else
			{
				offset = y * f->line_size + (x * f->bits_per_pixel / 8);
				*(int *)(f->addr + offset) = 0x00000000;
			}
			y++;
		}
		x++;
	}
}

int main(void)
{
	t_box	*f;

	f = (t_box *)malloc(sizeof (t_box) * 1);
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, &f->line_size, &f->endian);
	f->scale_factor = 1.0;
	f->orig_x = WIDTH * 2.0 / 3.0;
	f->orig_y = HEIGHT / 2.0;
	draw(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_mouse_hook(f->win, mouse_zoom, f);

	mlx_hook(f->win, KeyPress, KeyPressMask, event_handler, f->mlx);
	mlx_loop(f->mlx);
}
