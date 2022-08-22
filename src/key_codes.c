/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_codes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:48:08 by albagarc          #+#    #+#             */
/*   Updated: 2022/08/22 10:50:08 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../lib/minilibx_macos/mlx.h"
#include "../inc/keycode_hook.h"
#include "../inc/defines.h"
#include <stdlib.h>
#include <stdio.h>

int     key_press(int keycode, t_all *all)
{


        printf("keycode:%d\n", keycode);
        if (keycode == ESC_KEY)
        {
                mlx_destroy_window(all->vars.mlx, all->vars.win);
                exit(0);
        }
//	if (keycode == Z_KEY)
//		all->map.points->coordinates[X] = all->map.points->coordinates[X]*10;

		
        return(0);
}

