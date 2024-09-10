/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:53:00 by athonda           #+#    #+#             */
/*   Updated: 2024/09/10 09:29:09 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_esc(int key, t_box *p)
{
	int	x;
	int	y;
	//void	*tmp;

	x = 0;
	y = 0;
	printf("Key in Win3 : %d\n",key);
	if (key==0xFF1B)
		mlx_destroy_window(p->mlx, p->win);
	else if (key == 65361)
	{
		x = -10;
		p->orig_x -= 10;
	}
	else if (key == 65363)
	{
		x = 10;
		p->orig_x += 10;
	}
	else if (key == 65362)
	{
		y = 10;
		p->orig_y -= 10;
	}
	else if (key == 65364)
	{
		y = -10;
		p->orig_y += 10;
	}
	printf("key press before clear\n");
	//tmp = p->img;
	//p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	mlx_clear_window(p->mlx, p->win);
	printf("key press before put\n");
	mlx_put_image_to_window(p->mlx, p->win, p->img, x, y);
	return (0);
}

int	mouse_zoom(int button,int x,int y, t_box *p)
{
	double	scale_factor;

	printf("Mouse in Win1, button %d at %dx%d. p-value:%p\n",button,x,y,p);
	if (button == 4)
		scale_factor = ZOOM_IN_FACTOR;
	else if (button == 5)
		scale_factor = ZOOM_OUT_FACTOR;
	else
		return (0);
	p->scale_factor *= scale_factor;
	p->orig_x = x - (x - p->orig_x) / scale_factor;
	p->orig_y = y - (y - p->orig_y) / scale_factor;
	init_again(p);
	printf("mouse zoom before loop hook\n");
	mlx_destroy_image(p->mlx, p->img);
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	draw(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	return (0);
}

int	loop_hook(t_box *p)
{
//	mlx_destroy_image(p->mlx, p->img);
//	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	printf("loop hook before draw\n");
	fflush(stdout);
	draw(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	return (0);
}
