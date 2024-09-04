/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:47:30 by athonda           #+#    #+#             */
/*   Updated: 2024/09/04 13:09:18 by athonda          ###   ########.fr       */
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

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*win;
	void	*img;
	void	*img_file;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	char	*addr;
	int		offset;
	int		x;
	int		y;
	int		xpm_x;
	int		xpm_y;
	double	cx;
	double	cy;



	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World");

	img_file = mlx_xpm_file_to_image(mlx, "./minilibx-linux/test/unknowns.xpm", &xpm_x, &xpm_y);
	mlx_put_image_to_window(mlx, mlx_win, img_file, 0, 0);

	addr = mlx_get_data_addr(img_file, &bits_per_pixel, &line_size, &endian);
	printf("bytes per pixel: %d\n", bits_per_pixel);
	printf("line size: %d\n", line_size);
	printf("endian: %d\n", endian);
	printf("xpm_x: %d\n", xpm_x);
	printf("xpm_y: %d\n", xpm_y);

	x = 0;
	while (x < 300)
	{
		y = 0;
		while (y < 300)
		{
			if((y <= sqrt(10000 - pow((x - 100), 2)) + 100) && (y >= sqrt(10000 - pow((x - 100), 2)) * -1 + 100))
			{
				offset = y * line_size + (x * bits_per_pixel / 8);
				*(int *)(addr + offset) = 0x00FF0000;
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img_file, 0, 0);

	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fractol");
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	addr = mlx_get_data_addr(img, &bits_per_pixel, &line_size, &endian);
	printf("bytes per pixel: %d\n", bits_per_pixel);
	printf("line size: %d\n", line_size);
	printf("endian: %d\n", endian);
	printf("xpm_x: %d\n", xpm_x);
	printf("xpm_y: %d\n", xpm_y);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			cx = (x - (WIDTH * 2.0 / 3.0)) * 4.0 / WIDTH;
			cy = (y - HEIGHT / 2.0) * 4.0 / WIDTH;
			if (mandelbrot(cx, cy) == 100)
			{
				offset = y * line_size + (x * bits_per_pixel / 8);
				*(int *)(addr + offset) = 0x00FF0000;
			}
			else
			{
				offset = y * line_size + (x * bits_per_pixel / 8);
				*(int *)(addr + offset) = 0x00000000;
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_mouse_hook(win,mouse_zoom,0);

	mlx_hook(win, KeyPress, KeyPressMask, event_handler, mlx);
	mlx_loop(mlx);
}
