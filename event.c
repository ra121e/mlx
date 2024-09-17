/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:53:00 by athonda           #+#    #+#             */
/*   Updated: 2024/09/17 23:19:32 by athonda          ###   ########.fr       */
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
		p->red_k = -0.02;
		p->green_k = -0.13;
		p->blue_k = -0.13;
	}
	else if (key == 98)
	{
		p->red_k = -0.02;
		p->green_k = -0.08;
		p->blue_k = -0.13;
	}
	else if (key == 103)
	{
		p->red_k = -0.13;
		p->green_k = -0.13;
		p->blue_k = -0.02;
	}
	else if (key == 114)
	{
		p->red_k = -0.13;
		p->green_k = -0.02;
		p->blue_k = -0.04;
	}
	else if (key == 65361)
		p->orig_x += 20;
	else if (key == 65363)
		p->orig_x -= 20;
	else if (key == 65362)
		p->orig_y += 20;
	else if (key == 65364)
		p->orig_y -= 20;
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
	char	buffer[256];

	ft_dtoa((1 / p->scale_factor), buffer, 6);
	draw(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_string_put(p->mlx, p->win, (WIDTH / 2) - 20, 700 ,0x0067c0, buffer);
	return (0);
}
