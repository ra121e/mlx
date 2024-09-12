/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:53:00 by athonda           #+#    #+#             */
/*   Updated: 2024/09/12 22:40:54 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_box *p)
{
	printf("close window\n");
	finish(p, 1);
	return (0);
}

int	key_color(int key, t_box *p)
{
	if (key == 32)
	{
		p->red = 255;
		p->green = 255;
		p->blue = 255;
	}
	else if (key == 98)
	{
		p->red = 64;
		p->green = 64;
		p->blue = 255;
	}
	else if (key == 103)
	{
		p->red = 64;
		p->green = 255;
		p->blue = 64;
	}
	return (0);
}

int	key_esc(int key, t_box *p)
{
	printf("Key in Win3 : %d\n",key);
	if (key==0xFF1B)
		finish(p, 1);
	else if (key == 65361)
		p->orig_x -= 20;
	else if (key == 65363)
		p->orig_x += 20;
	else if (key == 65362)
		p->orig_y -= 20;
	else if (key == 65364)
		p->orig_y += 20;
	init_again(p);
	printf("key press before clear\n");
	mlx_clear_window(p->mlx, p->win);
	printf("key press before put\n");
	draw(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	return (0);
}

int	mouse_zoom(int button,int x,int y, t_box *p)
{
	double	scale_factor;

	printf("Mouse in Win1, button %d at %dx%d. zoom:%lf\n",button,x,y,1/p->scale_factor);
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
	return (0);
}

int	loop_hook(t_box *p)
{
	printf("loop hook before draw: iter %d\n", p->iter);
	fflush(stdout);
	draw(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	return (0);
}
