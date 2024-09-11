/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:23:11 by athonda           #+#    #+#             */
/*   Updated: 2024/09/11 18:33:20 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	finish(t_box *p, int exit_code)
{
	if (!p)
		exit(exit_code);
	if (p->img)
		mlx_destroy_image(p->mlx, p->img);
	if (p->win)
		mlx_destroy_window(p->mlx, p->win);
	if (p->mlx)
	{
	//	mlx_loop_end(p->mlx);
		mlx_destroy_display(p->mlx);
		free(p->mlx);
	}
	free(p);
	exit(exit_code);
}