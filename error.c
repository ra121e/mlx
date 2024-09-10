/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:20:32 by athonda           #+#    #+#             */
/*   Updated: 2024/09/09 23:32:41 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_arg(void)
{
	ft_putstr_fd("format error\n", 2);
	ft_putstr_fd("correct format: ./fractol argument (option for Julia)\n", 2);
	ft_putstr_fd("argument is m: Mandelbrot, j: Julia\n", 2);
	ft_putstr_fd("option for Julia is 1 or 2\n", 2);
}

void	error_julia(void)
{
	ft_putstr_fd("Julia needs option: ./fractol j option\n", 2);
	ft_putstr_fd("option for Julia is 1 or 2\n", 2);
}

void	error_fractal(void)
{
	ft_putstr_fd("correct format: ./fractol argument\n", 2);
	ft_putstr_fd("argument is m: Mandelbrot, j: Julia\n", 2);
}
