/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:24:12 by athonda           #+#    #+#             */
/*   Updated: 2024/09/10 08:09:03 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	fractal(t_box *p)
{
	size_t	n;

	n = 0;
	if (p->set == 'm')
		n = mandelbrot(p);
	else if (p->set == 'j')
		n = julia(p);
	return (n);
}