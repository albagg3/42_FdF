/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_codes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:48:08 by albagarc          #+#    #+#             */
/*   Updated: 2022/08/30 10:39:02 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../lib/minilibx_macos/mlx.h"
#include "../inc/keycode_hook.h"
#include "../inc/defines.h"
#include <stdlib.h>
#include <stdio.h>
#include "../inc/matrix_utils.h"
#include "../inc/utils.h"

int     key_press(int keycode, t_all *all)
{
	printf("keycode:%d\n", keycode);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(all->vars.mlx, all->vars.win);
		exit(0);
	}
//	if (keycode == KEY_Z)
//		all->map.points->coordinates[X] = all->map.points->coordinates[X]*10;
	if (keycode == KEY_1)
		{
			
			all->map.ang[X] += 10;

			
			//primero se rotan los valores del punto
//			rotation_x(all->map.total_size, all->map.points, all->map.projected,ang);
			//despues dibujar el mapa
		
		}
	if (keycode == KEY_R)
	{
		all->map.ang[X] = 0;
		

	}
	draw_map(all);
        return(0);
}

