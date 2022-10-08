/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:25:11 by albagarc          #+#    #+#             */
/*   Updated: 2022/10/08 12:28:22 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../lib/libft_src/libft.h"
#include "../inc/defines.h"
#include "../inc/utils.h"
#include "../lib/minilibx_macos/mlx.h"


//funcion que nos haga una copia de los puntos originales para no perder nunca la referencia de cuales son los puntos originales.
void map_init(t_map *map)
{
	map->ang[X] = 0;
	map->ang[Y] = 0;
	map->ang[Z] = 0;
	map->scale = 1;
}


void	copy_map_points(t_point *src, t_point *dst, int total_size)
{
	int i;

	i = 0;
	while (i < total_size)
	{
		dst[i] = src[i];
		i++;
	}
}

void	black_background(t_data *data)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (y <= WINY)
	{
		x = 0;
		while(x <= WINX)
		{
			my_mlx_pixel_put(data,x,y,BLACK);
			x++;
		}
		y++;
	}
}

//llamamos a esta funcion desde key_press y en funcion a las teclas que se hayan presionado nos guarda unas  en la estructura y ejecuta todas estas funciones cada vez.

void	draw_map(t_all *all)
{
	t_point *copy_points;
	
	copy_points = malloc (sizeof(t_point) * all->map.total_size);
	//funcion que me pinte todo el fondo de negro
	black_background(&all->data);
	copy_map_points(all->map.points, copy_points, all->map.total_size); // copy map
	rotation_x(all->map.total_size, copy_points, copy_points,all->map.ang[X]); // parse map
	rotation_y(all->map.total_size, copy_points, copy_points,all->map.ang[Y]);
	rotation_z(all->map.total_size, copy_points, copy_points,all->map.ang[Z]);
	zoom(copy_points, all->map.total_size, all->map.scale);
	draw_points(all, copy_points);
	draw_map_line(all, all->map.total_size,&all->map, copy_points); 
	free(copy_points);
	mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->data.img, 0, 0);
}
