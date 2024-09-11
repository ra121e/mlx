/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:47:30 by athonda           #+#    #+#             */
/*   Updated: 2024/09/11 09:52:06 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_fractal(t_box *p, char *av[])
{
	if (av[1][0] == 'm')
		p->set = 'm';
	else if(av[1][0] == 'j')
		p->set = 'j';
	else
		return ;
}

int	check_arg(int ac, char *av[], t_box *p)
{
	set_fractal(p, av);
	if (av[1][0] == 'j' && ac != 4)
	{
		error_julia();
		return (0);
	}
	else if (av[1][0] == 'm' && ac != 2)
	{
		error_fractal();
		return (0);
	}
	else if (!(av[1][0] == 'm' || av[1][0] == 'j'))
	{
		error_fractal();
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_box	*p;

	if (ac < 2)
	{
		error_arg();
		return (0);
	}
	p = (t_box *)malloc(sizeof (t_box) * 1);
	if (p == NULL)
		return (0);
	init_var(p);
	if (check_arg(ac, av, p) == 0)
		return (0);
	init(p);
	draw(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_mouse_hook(p->win, mouse_zoom, p);
	mlx_key_hook(p->win, key_esc, p);
	mlx_loop_hook(p->mlx, loop_hook, p);
	//mlx_hook(p->win, 17, 0, close_window, p);
	//mlx_hook(p->win, 2, 1L << 0, key_esc, p);
	mlx_loop(p->mlx);
	return (0);
}
