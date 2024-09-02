#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include <math.h>
#include "mlx.h"

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
	void	*img;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	char	*addr;
	int		offset;
	int		x;
	int		y;
	int		xpm_x;
	int		xpm_y;
	int		i;
	int		j;



	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World");

	img = mlx_xpm_file_to_image(mlx, "./minilibx-linux/test/unknowns.xpm", &xpm_x, &xpm_y);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);

	//img = mlx_new_image(mlx, 1920, 1080);
	addr = mlx_get_data_addr(img, &bits_per_pixel, &line_size, &endian);
	printf("bytes per pixel: %d\n", bits_per_pixel);
	printf("line size: %d\n", line_size);
	printf("endian: %d\n", endian);

	x = 0;
	while (x < 500)
	{
		y = 0;
		while (y < 200)
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

	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);

	// mlx_hook(mlx_win, KeyPress, KeyPressMask, event_handler, mlx);
	 mlx_loop(mlx);
}
