/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:53:00 by athonda           #+#    #+#             */
/*   Updated: 2024/09/04 12:51:43 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
int	key_win3(int key,void *p)
{
  printf("Key in Win3 : %d\n",key);
  if (key==0xFF1B)
    mlx_destroy_window(mlx,win3);
}
*/

int	mouse_zoom(int button,int x,int y, void *p)
{
  printf("Mouse in Win1, button %d at %dx%d. p-value:%p\n",button,x,y,p);
  return (0);
}
