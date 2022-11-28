/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:46:51 by albagarc          #+#    #+#             */
/*   Updated: 2022/11/28 14:34:40 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/utils.h"
#include <math.h>

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

void	draw_map_line(t_all *all, int len, t_map *map, t_point *proyected)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (i >= len - (int)map->limits.coord[X])	//nos encontramos en la ultima fila del mapa
			draw_line(all, proyected[i], proyected[i + 1]);	//pintamos horizontales
		else if (i == 0 || (i + 1) % (int)map->limits.coord[X] != 0)	//nos encontramos en el primer punto del mapa o en todos los puntos que no sean el ultimo de fila
		{
			draw_line(all, proyected[i], proyected[i + 1]);
			draw_line(all, proyected[i], proyected[i + (int)map->limits.coord[X]]);
		}
		else																//nos encontramos en elos ultimos de fila
			draw_line(all, proyected[i], proyected[i + (int)map->limits.coord[X]]);
		i++;
	}
}
