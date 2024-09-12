/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:20:32 by athonda           #+#    #+#             */
/*   Updated: 2024/09/12 10:13:20 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_arg(void)
{
	ft_putstr_fd("format error\n", 2);
	ft_putstr_fd("./fractol argument (option1) (option2)\n", 2);
	ft_putstr_fd("argument is m..: Mandelbrot, j..: Julia\n", 2);
	ft_putstr_fd("option is ONLY for Julia, 2 float numbers(-2 to 2)\n", 2);
	ft_putstr_fd("sample option : -0.79 0.15\n", 2);
	ft_putstr_fd("sample option : -0.162 1.04\n", 2);
	ft_putstr_fd("sample option : 0.3 -0.1\n", 2);
	ft_putstr_fd("sample option : -0.17 0.66\n", 2);
}

void	error_julia(void)
{
	ft_putstr_fd("Julia needs 2 options: ./fractol j option option\n", 2);
	ft_putstr_fd("option is ONLY for Julia, 2 float numbers(-2 to 2)\n", 2);
	ft_putstr_fd("sample option 1: -0.79 0.15\n", 2);
	ft_putstr_fd("sample option 2: -0.162 1.04\n", 2);
	ft_putstr_fd("sample option 3: 0.3 -0.1\n", 2);
	ft_putstr_fd("sample option 4: -0.17 0.66\n", 2);
}

void	error_fractal(void)
{
	ft_putstr_fd("correct format: ./fractol argument\n", 2);
	ft_putstr_fd("argument is m: Mandelbrot, j: Julia\n", 2);
}
