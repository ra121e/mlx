/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:53:00 by athonda           #+#    #+#             */
/*   Updated: 2024/09/06 17:30:45 by athonda          ###   ########.fr       */
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
	mlx_destroy_image(p->mlx, p->img);
	//mlx_clear_window(p->mlx, p->win);
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	//addr = mlx_get_data_addr(p->img, &bits_per_pixel, &line_size, &endian);
	draw(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	return (0);
}
