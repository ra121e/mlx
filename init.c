/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:54:21 by athonda           #+#    #+#             */
/*   Updated: 2024/09/13 13:43:19 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_var(t_box *p)
{
	p->mlx = NULL;
	p->win = NULL;
	p->img = NULL;
	p->addr = NULL;
	p->bpp = 0;
	p->line_size = 0;
	p->endian = 0;
	p->set = '\0';
	p->jx = JULIA_CX;
	p->jy = JULIA_CY;
	p->scale_factor = 0.0;
	p->orig_x = 0.0;
	p->orig_y = 0.0;
	p->x = 0;
	p->y = 0;
	p->cx = 0.0;
	p->cy = 0.0;
	p->iter = 0;
	p->red = 255;
	p->green = 255;
	p->blue = 255;
}

int	init(t_box *p)
{
	p->mlx = mlx_init();
	if (p->mlx == NULL)
		return (1);
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "fractol");
	if (p->win == NULL)
		return (1);
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	if (p->img == NULL)
		return (1);
	p->addr = mlx_get_data_addr(p->img, &p->bpp, &p->line_size, &p->endian);
	if (p->addr == NULL)
		return (1);
	p->scale_factor = 1.0;
	p->orig_x = WIDTH * 2.0 / 3.0;
	p->orig_y = HEIGHT / 2.0;
	p->iter = 0;
	init_again(p);
	return (0);
}

void	init_again(t_box *p)
{
	int	i;
	int	j;

	p->iter = 0;
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
}
