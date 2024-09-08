/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:53:00 by athonda           #+#    #+#             */
/*   Updated: 2024/09/08 09:13:47 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_esc(int key, t_box *p)
{
	printf("Key in Win3 : %d\n",key);
	if (key==0xFF1B)
	mlx_destroy_window(p->mlx, p->win);
	return (0);
}

int	mouse_zoom(int button,int x,int y, t_box *p)
{
	double	scale_factor;
	int		i;
	int		j;

	printf("Mouse in Win1, button %d at %dx%d. p-value:%p\n",button,x,y,p);
	if (button == 4)
		scale_factor = 0.9;
	else if (button == 5)
		scale_factor = 1.1;
	else
		return (0);
	p->scale_factor *= scale_factor;
	p->orig_x = x - (x - p->orig_x) / scale_factor;
	p->orig_y = y - (y - p->orig_y) / scale_factor;
	p->iter = 0;
	p->trigger = 1;
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			p->zr[i][j] = 0.0;
			p->zi[i][j] = 0.0;
			p->div[i][j] = 0.0;
			j++;
		}
		i++;
	}
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
