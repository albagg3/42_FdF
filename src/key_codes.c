/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_codes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:48:08 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/01 11:51:22 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../lib/minilibx_macos/mlx.h"
#include "../inc/keycode_hook.h"
#include "../inc/defines.h"
#include <stdlib.h>
#include <stdio.h>
#include "../inc/utils.h"

int	key_press1(int keycode, t_all *all)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(all->vars.mlx, all->vars.win);
		exit(0);
	}
	if (keycode == KEY_UP)
	{
		all->map.ang[X] += 10;
		all->map.ang[Y] += 10;
	}
	if (keycode == KEY_DOWN)
	{
		all->map.ang[X] -= 10;
		all->map.ang[Y] -= 10;
	}
	if (keycode == KEY_RIGHT)
	{
		all->map.ang[Y] += 10;
	}
	if (keycode == KEY_LEFT)
	{
		all->map.ang[Y] -= 10;
	}
	draw_map(all);
	return (0);
}

int	key_press2(int keycode, t_all *all)
{
	if (keycode == KEY_I)
	{
		all->map.ang[X] = 30;
		all->map.ang[Y] = 330;
		all->map.ang[Z] = 30;
	}
	if (keycode == KEY_P)
	{
		all->map.ang[X] = 90;
		all->map.ang[Y] = 0;
		all->map.ang[Z] = 0;
	}
	if (keycode == KEY_Z)
	{
		all->map.divisor += 1;
	}
	if (keycode == KEY_X)
	{
		if (all->map.divisor > 1)
			all->map.divisor -= 1;
	}
	draw_map(all);
	return (0);
}

int	key_press(int keycode, t_all*all)
{
	key_press2(keycode, all);
	key_press1(keycode, all);
	return (0);
}
