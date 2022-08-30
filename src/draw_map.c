/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:25:11 by albagarc          #+#    #+#             */
/*   Updated: 2022/08/30 10:02:13 by albagarc         ###   ########.fr       */
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

void	draw_map(t_all *all)
{
	t_point *copy_points;
	
	copy_points = malloc (sizeof(t_point) * all->map.total_size);
	copy_map_points(all->map.points, copy_points, all->map.total_size); // copy map
	rotation_x(all->map.total_size, copy_points, copy_points,all->map.ang[X]); // parse map
	draw_points(all, copy_points);
	free(copy_points);
	mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->data.img, 0, 0);


}
