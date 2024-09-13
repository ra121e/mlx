/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:53:00 by athonda           #+#    #+#             */
/*   Updated: 2024/09/13 12:46:53 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_box *p)
{
	finish(p, 1);
	return (0);
}

int	key_esc(int key, t_box *p)
{
	if (key == 0xFF1B)
		finish(p, 1);
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
		p->blue = 200;
	}
	else if (key == 65361)
		p->orig_x -= 20;
	else if (key == 65363)
		p->orig_x += 20;
	else if (key == 65362)
		p->orig_y -= 20;
	else if (key == 65364)
		p->orig_y += 20;
	init_again(p);
	return (0);
}

int	mouse_zoom(int button, int x, int y, t_box *p)
{
	double	scale_factor;

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
	return (0);
}

int	loop_hook(t_box *p)
{
	draw(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	return (0);
}
