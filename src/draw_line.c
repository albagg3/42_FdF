/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:46:51 by albagarc          #+#    #+#             */
/*   Updated: 2022/11/29 15:55:17 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/utils.h"
#include <math.h>

//Utilizando el algoritmo de Bresenham calculamos los pixels de una linea

int	draw_line(t_all *all, t_point start, t_point end)
{
	t_point	delta;
	t_point	pixel;
	int		pixels;
	int		len;

	delta.coord[X] = end.coord[X] - start.coord[X];
	delta.coord[Y] = end.coord[Y] - start.coord[Y];
	pixels = sqrt((delta.coord[X] * delta.coord[X]) + \
		(delta.coord[Y] * delta.coord[Y]));
	len = pixels;
	delta.coord[X] /= pixels;
	delta.coord[Y] /= pixels;
	pixel.coord[X] = start.coord[X];
	pixel.coord[Y] = start.coord[Y];
	while (pixels > 0)
	{
		my_mlx_pixel_put(&all->data, pixel.coord[X], pixel.coord[Y] \
			, start.color);
		pixel.coord[X] += delta.coord[X];
		pixel.coord[Y] += delta.coord[Y];
		pixels = pixels - 1;
	}
	return (1);
}

// Pintamos las lineas del mapa:
// if -> comprobamos la ultima fila del mapa y pintamos las horizontales.
// else if -> comprobamos el primer punto del mapa y pintamos todas lo
// puntos que no sean ultimo punto de fila.
// else -> nos encontramos en los ultimos puntos de cada fila.

void	draw_map_line(t_all *all, int len, t_map *map, t_point *proyected)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (i >= len - (int)map->limits.coord[X])
			draw_line(all, proyected[i], proyected[i + 1]);
		else if (i == 0 || (i + 1) % (int)map->limits.coord[X] != 0)
		{
			draw_line(all, proyected[i], proyected[i + 1]);
			draw_line(all, proyected[i], proyected[i + \
				(int)map->limits.coord[X]]);
		}
		else
			draw_line(all, proyected[i], proyected[i + \
				(int)map->limits.coord[X]]);
		i++;
	}
}

int	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WINX || y >= WINY || x < 0 || y < 0)
		return (-1);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}

void	draw_points(t_all *all, t_point *copy_points)
{
	int	i;

	i = 0;
	while (i < all->map.total_size)
	{
		my_mlx_pixel_put(&all->data, copy_points[i].coord[X] + WINX / 2, \
			copy_points[i].coord[Y] + WINY / 2, 0xff0000);
		i++;
	}
}
