/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:47:30 by athonda           #+#    #+#             */
/*   Updated: 2024/09/05 13:26:40 by athonda          ###   ########.fr       */
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

void	draw(t_box *box, double scale_factor)
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
			cx = (x - box->orig_x) * (scale_factor * 4.0 / WIDTH);
			cy = (y - box->orig_y) * (scale_factor * 4.0 / WIDTH);
			if (mandelbrot(cx, cy) == 100)
			{
				offset = y * box->line_size + (x * box->bits_per_pixel / 8);
				*(int *)(box->addr + offset) = 0x00FF0000;
			}
			else
			{
				offset = y * box->line_size + (x * box->bits_per_pixel / 8);
				*(int *)(box->addr + offset) = 0x00000000;
			}
			y++;
		}
		x++;
	}
}

int main(void)
{
	t_box	*box;
	void	*mlx;
	void	*win;
	void	*img;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	char	*addr;
	double	scale_factor;

	box = (t_box *)malloc(sizeof (t_box) * 1);
	mlx = mlx_init();
	printf("init\n");
	box->mlx = mlx;
	printf("assigne init\n");
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fractol");
	printf("window\n");
	box->win = win;
	printf("assigne window\n");
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	printf("mage\n");
	box->img = img;
	printf("assinge mage\n");
	addr = mlx_get_data_addr(img, &bits_per_pixel, &line_size, &endian);
	printf("bytes per pixel: %d\n", bits_per_pixel);
	printf("line size: %d\n", line_size);
	printf("endian: %d\n", endian);
	box->addr = addr;
	box->bits_per_pixel = bits_per_pixel;
	box->line_size = line_size;
	box->endian = endian;
	scale_factor = 1.0;
	box->scale_factor = 1.0;
	box->orig_x = WIDTH * 2.0 / 3.0;
	box->orig_y = HEIGHT / 2.0;
	draw(box, scale_factor);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_mouse_hook(win, mouse_zoom, box);

	mlx_hook(win, KeyPress, KeyPressMask, event_handler, mlx);
	mlx_loop(mlx);
}
